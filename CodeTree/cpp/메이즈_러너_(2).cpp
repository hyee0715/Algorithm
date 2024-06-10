#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, k; //n: 미로의 크기, m: 참가자 수, k: 게임 시간
int answer; //모든 참가자의 이동 거리
vector<vector<vector<int> > > personBoard;
vector<vector<int> > board;
pair<int, int> exitLocation;

int dx[] = { -1, 1, 0, 0 }; //상하좌우
int dy[] = { 0, 0, -1, 1 };

void input() {
	cin >> n >> m >> k;

	board.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	personBoard.assign(n, vector<vector<int> >(n, vector<int>(0)));

	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		personBoard[a - 1][b - 1].push_back(i);
	}

	cin >> a >> b;
	board[a - 1][b - 1] = -1;
	exitLocation = { a - 1, b - 1 };
}

bool isPersonBoardEmpty() {
	for (int i = 0; i < personBoard.size(); i++) {
		for (int j = 0; j < personBoard[i].size(); j++) {
			if (!personBoard[i][j].empty()) {
				return false;
			}
		}
	}

	return true;
}

int getDistance(int x1, int y1, int x2, int y2) {

	return abs(x1 - x2) + abs(y1 - y2);
}

bool locationsCompare(pair<int, int> a, pair<int, int> b) {
	if (a.first <= b.first) {
		if (a.first == b.first) {
			if (a.second <= b.second) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

pair<pair<int, int>, int> getNextLocation(int x, int y) { //현재 칸 x,y로부터 상하좌우 4칸 중 가장 알맞은 위치 찾기
	vector<pair<int, int> > locations; //거리, 방향 인덱스

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) { //범위 내에 위치할 것.
			continue;
		}

		if (board[nx][ny] != 0 && board[nx][ny] != -1) {//board가 0이거나 -1일 것.
			continue;
		}

		int originalDist = getDistance(x, y, exitLocation.first, exitLocation.second);
		int newDist = getDistance(nx, ny, exitLocation.first, exitLocation.second);

		if (originalDist <= newDist) { //현재 칸 보다 출구까지 가까울 것
			continue;
		}

		locations.push_back({ newDist, i });
	}

	if (locations.empty()) {
		return { { -1, -1 }, -1 };
	}

	sort(locations.begin(), locations.end(), locationsCompare);

	int targetX = x + dx[locations[0].second];
	int targetY = y + dy[locations[0].second];

	return { { targetX, targetY }, locations[0].first };
}

void move() { //모든 참가자 이동
	vector<vector<vector<int> > > temp(n, vector<vector<int> >(n, vector<int>(0)));

	for (int i = 0; i < personBoard.size(); i++) {
		for (int j = 0; j < personBoard[i].size(); j++) {
			for (int k = 0; k < personBoard[i][j].size(); k++) {
				int personNum = personBoard[i][j][k];

				pair<pair<int, int>, int> nextLocation = getNextLocation(i, j); // 이동 위치 x, y, 거리

				if (nextLocation.first.first == -1 && nextLocation.first.second == -1 && nextLocation.second == -1) {
					temp[i][j].push_back(personNum);

					continue; //움직일 곳 없으면 이동 x
				}

				int x = nextLocation.first.first;
				int y = nextLocation.first.second;
				int dist = nextLocation.second;

				temp[x][y].push_back(personNum);

				answer++;
			}
		}
	}

	//출구로 참가자가 이동했다면, 비우기
	temp[exitLocation.first][exitLocation.second].clear();

	personBoard = temp;
}

bool checkSpace(int size, int x, int y) { //사람 1명 이상 & 출구가 존재하는지 확인
	int personFlag = false, exitFlag = false;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (!personBoard[i][j].empty()) {
				personFlag = true;
			}

			if (board[i][j] == -1) {
				exitFlag = true;
			}
		}
	}

	if (personFlag && exitFlag) {
		return true;
	}

	return false;
}

bool spacesCompare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.first <= b.first.first) {
		if (a.first.first == b.first.first) {
			if (a.first.second <= b.first.second) {
				if (a.first.second == b.first.second) {
					if (a.second <= b.second) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

pair<pair<int, int>, int> findSpace() {
	vector<pair<pair<int, int>, int> > spaces; //공간 모서리 크기, 좌상단 행, 좌상단 열

	for (int num = 2; num <= n; num++) {
		for (int i = 0; i <= n - num; i++) {
			for (int j = 0; j <= n - num; j++) {
				if (checkSpace(num, i, j)) {
					spaces.push_back({ { num, i }, j });
				}
			}
		}
	}

	if (spaces.empty()) {
		return { {-1, -1}, -1 };
	}

	sort(spaces.begin(), spaces.end(), spacesCompare);

	return spaces[0];
}

void rotateBoard(int x, int y, int size) {
	vector<vector<int> > temp = board;

	int rowStart = x;
	int rowEnd = x + size - 1;
	int colStart = y;
	int colEnd = y + size - 1;

	int r = rowStart;
	int c = colStart;

	for (int j = colEnd; j >= colStart; j--) {
		for (int i = rowStart; i <= rowEnd; i++) {
			temp[i][j] = board[r][c];
			c++;
		}
		r++;
		c = colStart;
	}

	board = temp;
}

void rotatePersonBoard(int x, int y, int size) {
	vector<vector<vector<int> > > temp = personBoard;

	int rowStart = x;
	int rowEnd = x + size - 1;
	int colStart = y;
	int colEnd = y + size - 1;

	int r = rowStart;
	int c = colStart;

	for (int j = colEnd; j >= colStart; j--) {
		for (int i = rowStart; i <= rowEnd; i++) {
			temp[i][j] = personBoard[r][c];
			c++;
		}
		r++;
		c = colStart;
	}

	personBoard = temp;
}

void updateBoard(int x, int y, int size) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (board[i][j] > 0) {
				board[i][j]--;
			}

			if (board[i][j] == -1) {
				exitLocation = { i, j };
			}
		}
	}
}

void rotate() {
	//보드 두 개 다 돌려야됨
	pair<pair<int, int>, int> space = findSpace();

	if (space.first.first == -1 && space.first.second == -1 && space.second == -1) {
		return;
	}

	int size = space.first.first;
	int x = space.first.second;
	int y = space.second;

	rotateBoard(x, y, size);
	rotatePersonBoard(x, y, size);

	updateBoard(x, y, size);
}

void solution() {
	answer = 0;

	for (int round = 0; round < k; round++) {
		if (isPersonBoardEmpty()) { //모든 참가자가 탈출에 성공한다면 종료
			break;
		}

		move();

		rotate();
	}

	cout << answer << "\n" << exitLocation.first + 1 << " " << exitLocation.second + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}