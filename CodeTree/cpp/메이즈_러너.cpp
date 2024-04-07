#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Participant {
	int num;
	int x;
	int y;
	bool status; //탈출 x : false / 탈출 o : true
	int distance; //총 이동 거리
};

int n, m, k;
vector<vector<int > > board; //미로 격자
vector<vector<vector<int> > > participantBoard; //참가자 번호 격자 (여러 명 위치 가능)
map<int, Participant> participantMap; //참가자 번호, 참가자 (참가자 번호는 1~m)
pair<int, int> exitLocation;

int dx[] = { -1, 1, 0, 0 }; //상하좌우
int dy[] = { 0, 0, 1, -1 }; 

void input() {
	cin >> n >> m >> k;

	board.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;

		Participant participant = { i, a - 1, b - 1, false, 0 };
		participantMap[i] = participant;
	}

	cin >> a >> b;
	board[a - 1][b - 1] = -1;
	exitLocation = { a - 1, b - 1 };
}

bool checkParticipants() {
	//모든 참가자가 미로를 탈출했다면 true 리턴, 아니면 false 리턴
	for (pair<int, Participant> participant : participantMap) {
		if (participant.second.status == false) {
			return false;
		}
	}

	return true;
}

int getDistanceToExit(int x, int y) {
	//현재 좌표로부터 출구까지의 최단 거리

	return abs(x - exitLocation.first) + abs(y - exitLocation.second);
}

vector<pair<int, int> > getNextDistances(int x, int y, int curDistance) {
	vector<pair<int, int> > distances; //거리, 방향

	for (int i = 0; i < 4; i++) {
		//벽있거나, 범위 밖이거나, 현재보다 멀면 x
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			continue;
		}

		if (board[nx][ny] > 0) {
			continue;
		}

		int nextDist = getDistanceToExit(nx, ny);
		if (nextDist >= curDistance) {
			continue;
		}

		distances.push_back({ nextDist, i });
	}

	return distances;
}

void moveParticipants() {
	for (pair<int, Participant> part : participantMap) {
		int num = part.first;
		int x = part.second.x;
		int y = part.second.y;
		int curDist = part.second.distance;
		int status = part.second.status;

		if (status == true) {
			continue;
		}

		//현재 참가자의 칸으로부터 출구까지 거리 구하기
		int curDistance = getDistanceToExit(x, y);

		//참가자 1명씩 돌면서 상하좌우 방향 당 최단거리 구하기
		//벽이 있거나, 현재보다 가깝지 않으면 x
		vector<pair<int, int> > nextDistances = getNextDistances(x, y, curDistance);

		//비어있으면 움직이지 않음
		if (nextDistances.empty()) {
			continue;
		}

		//방향 당 최단거리 중에 가장 가까운 거 뽑기 (상하우선)
		sort(nextDistances.begin(), nextDistances.end());

		int shortestDist = nextDistances[0].first;
		int dir = nextDistances[0].second;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		participantMap[num].x = nx;
		participantMap[num].y = ny;
		participantMap[num].distance = curDist + 1;

		//뽑은 방향대로 한 명씩 움직이기
		//움직인 곳이 출구이면
		if (exitLocation.first == nx && exitLocation.second == ny) {
			participantMap[num].status = true;
		}
		else {
			//출구 아니면
			participantMap[num].status = false;
		}
	}
}

void settingParticipants() {
	participantBoard.assign(n, vector < vector<int> >(n, vector<int>(0)));

	for (pair<int, Participant> part : participantMap) {
		int num = part.first;
		int x = part.second.x;
		int y = part.second.y;

		if (part.second.status == false) {
			participantBoard[x][y].push_back(num);
		}
	}
}

bool checkSquare(int x, int y, int size) {
	//x, y가 좌측 상단이고, 변이 size인 사각형 안에 참가자 최소 1 + 출구가 있는지 확인 -> 있으면 true, 없으면 false
	bool partFlag = false;
	bool exitFlag = false;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (board[i][j] == -1) {
				exitFlag = true;
			}
			else {
				vector<int> partBoard = participantBoard[i][j];

				for (int k = 0; k < partBoard.size(); k++) {
					int partNum = partBoard[k];

					Participant part = participantMap[partNum];

					if (part.status == false) {
						partFlag = true;
					}
				}
			}
		}
	}

	if (partFlag == true && exitFlag == true) {
		return true;
	}

	return false;
}

pair<pair<int, int>, int> findSmallestSquare() {
	//return : 정사각형 변 길이, 행 좌표, 열 좌표
	//정사각형 2*2부터 n*n 까지 돌면서 찾을 때까지 반복

	for (int size = 2; size <= n; size++) {
		for (int i = 0; i <= board.size() - size; i++) {
			for (int j = 0; j <= board[0].size() - size; j++) {
				if (checkSquare(i, j, size)) {
					return { {size, i}, j };
				}
			}
		}
	}

	return { {-1, -1}, -1 };
}

void rotateSquare(int x, int y, int size) {
	//보드, 참가자 보드 다 돌리고, 참가자 map 모두 수정
	vector<int> v;
	map<int, vector<int> > tempMap; //v 인덱스, 참가자 번호

	int idx = 0;
	//일단 보드 돌리기
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			v.push_back(board[i][j]);

			for (int k = 0; k < participantBoard[i][j].size(); k++) {
				tempMap[idx].push_back(participantBoard[i][j][k]);
			}

			idx++;
		}
	}

	idx = 0;
	for (int j = y + size - 1; j >= y; j--) {
		for (int i = x; i < x + size; i++) {
			board[i][j] = v[idx];

			participantBoard[i][j].clear();
			
			vector<int> tempV = tempMap[idx];

			for (int k = 0; k < tempV.size(); k++) {
				participantBoard[i][j].push_back(tempV[k]);

				Participant part = participantMap[tempV[k]];
				participantMap[tempV[k]].x = i;
				participantMap[tempV[k]].y = j;
			}

			idx++;
		}
	}
}

void renewExitLocation() {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == -1) {
				exitLocation = { i, j };
			}
		}
	}
}

void rotateBoard() {
	settingParticipants();

	//참가자 1 이상 + 출구 1 찾기인 정사각형 찾기 (r, c 작은 순)
	pair<pair<int, int>, int> smallestSquare = findSmallestSquare();

	int size = smallestSquare.first.first;
	int x = smallestSquare.first.second;
	int y = smallestSquare.second;

	//선택한 정사각형 내구도 0보다 큰 것들 내구도 -1 하기
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (board[i][j] > 0) {
				board[i][j]--;
			}
		}
	}

	//90도 시계방향 회전 시키기
	rotateSquare(x, y, size);

	//출구 찾아서 출구 위치도 같이 바꿔줌
	renewExitLocation();
}

int getDistanceSum() {
	int sum = 0;

	for (pair<int, Participant> part : participantMap) {
		int dist = part.second.distance;

		sum += dist;
	}

	return sum;
}

void solution() {
	for (int gameCnt = 0; gameCnt < k; gameCnt++) {
		//게임 k초만큼 반복

		//모든 참가자가 미로를 탈출했다면 즉시 게임 종료
		if (checkParticipants()) {
			break;
		}

		//참가자 이동
		moveParticipants();
	
		//미로 회전
		rotateBoard();
	}

	int distanceSum = getDistanceSum();

	cout << distanceSum << "\n" << exitLocation.first + 1 << " " << exitLocation.second + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}