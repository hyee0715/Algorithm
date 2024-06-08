#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int k, m; //k : 탐사의 반복 횟수, m : 벽면에 적힌 유물 조각의 개수
vector<vector<int> > board;
vector<int> wallVec;
queue<int> wall;
int answer;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void input() {
	cin >> k >> m;

	board.assign(5, vector<int>(5, 0));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}

	int a;
	for (int i = 0; i < m; i++) {
		cin >> a;
		wall.push(a);
	}
}

vector<vector<int> > rotate90(int a, int b, vector<vector<int> >& tempBoard1) {
	vector<vector<int> > tempBoard2 = tempBoard1;

	int startX = a - 1;
	int startY = b - 1;
	int endX = startX + 2;
	int endY = startY + 2;

	int x = startX, y = startY;

	for (int j = endY; j >= startY; j--) {
		for (int i = startX; i <= endX; i++) {
			tempBoard2[i][j] = tempBoard1[x][y];
			y++;
		}

		x++;
		y = startY;
	}

	return tempBoard2;
}

vector<vector<int> > rotate(int x, int y, int angle) {
	vector<vector<int> > tempBoard = board;

	if (angle == 90) {
		tempBoard = rotate90(x, y, tempBoard);
	} else if (angle == 180) {
		tempBoard = rotate90(x, y, tempBoard);
		tempBoard = rotate90(x, y, tempBoard);
	}
	else {
		tempBoard = rotate90(x, y, tempBoard);
		tempBoard = rotate90(x, y, tempBoard);
		tempBoard = rotate90(x, y, tempBoard);
	}

	return tempBoard;
}

int bfs(int a, int b, int num, vector<vector<int> >& tempBoard, vector<vector<bool> >& visit) { //num : 찾고자 하는 유물 종류 (1~7)
	//획득 가치 찾기
	//3개 이상 상하좌우 인접한 경우 찾기
	int count = 0;

	queue<pair<int, int> > q; //x, y, 인접 개수

	q.push({a, b});
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		count++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= tempBoard.size() || ny >= tempBoard[0].size()) continue;

			if (tempBoard[nx][ny] == num && visit[nx][ny] == false) {
				q.push({ nx, ny });
				visit[nx][ny] = true;
			}
		}
	}

	if (count <= 2) {
		count = 0;
	}

	return count;
}

vector<int> getValue(int x, int y) { //리턴: 90도 회전 시 가치, 180도 회전 시 가치, 270도 회전 시 가치
	vector<int> ret;

	//90도 회전
	vector<vector<int> > tempBoard = rotate(x, y, 90);

	int curValue = 0;
	vector<vector<bool> > visit(tempBoard.size(), vector<bool>(tempBoard[0].size(), false));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (visit[i][j] == false) {
				int val = bfs(i, j, tempBoard[i][j], tempBoard, visit);
				curValue += val;
			}
		}
	}

	ret.push_back(curValue);

	//180도 회전
	tempBoard = rotate(x, y, 180);

	curValue = 0;
	visit.assign(tempBoard.size(), vector<bool>(tempBoard[0].size(), false));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (visit[i][j] == false) {
				int val = bfs(i, j, tempBoard[i][j], tempBoard, visit);
				curValue += val;
			}
		}
	}
	ret.push_back(curValue);

	//270도 회전
	tempBoard = rotate(x, y, 270);

	curValue = 0;
	visit.assign(tempBoard.size(), vector<bool>(tempBoard[0].size(), false));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (visit[i][j] == false) {
				int val = bfs(i, j, tempBoard[i][j], tempBoard, visit);
				curValue += val;
			}
		}
	}
	ret.push_back(curValue);

	return ret;
}

bool compareRotatePoint(pair<pair<pair<int, int>, int>, int> a, pair<pair<pair<int, int>, int>, int> b) {
	//획득 가치 큰 순, 회전 각도 작은 순, 중심 좌표 열 작은 순, 행 작은 순
	int aValue = a.first.first.first;
	int bValue = b.first.first.first;

	int aAngle = a.first.first.second;
	int bAngle = b.first.first.second;

	int aCol = a.first.second;
	int bCol = b.first.second;

	int aRow = a.second;
	int bRow = b.second;

	if (aValue <= bValue) {
		if (aValue == bValue) {
			if (aAngle <= bAngle) {
				if (aAngle == bAngle) {
					if (aCol <= bCol) {
						if (aCol == bCol) {
							if (aRow <= bRow) {
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
		return false;
	}
	return true;
}

pair<pair<int, int>, int> getRotatePoint() { //조건에 맞는 회전 목표 찾기, 리턴 : 중심좌표 행 열, 회전각도
	vector<vector<int>> tempBoard = board;
	vector<pair<pair<pair<int, int>, int>, int> > v; //획득 가치, 회전 각도, 중심좌표 열, 행

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			vector<int> values = getValue(i, j); //i, j를 중심 좌표로 하여 90, 180, 270도 회전 했을 때 얻을 수 있는 유물 가치들

			v.push_back({ {{values[0], 90}, j}, i });
			v.push_back({ {{values[1], 180}, j}, i });
			v.push_back({ {{values[2], 270}, j}, i });
		}
	}
	
	sort(v.begin(), v.end(), compareRotatePoint);

	if (v[0].first.first.first == 0) {
		return { {-1, -1}, -1 };
	}

	return { {v[0].second, v[0].first.second}, v[0].first.first.second };
}


vector<pair<int, int> > bfs2(int a, int b, int num, vector<vector<int> >& tempBoard, vector<vector<bool> >& visit) { //num : 찾고자 하는 유물 종류 (1~7) //리턴 : 인접한 유물의 위치 배열
	//획득 가치 찾기
	//3개 이상 상하좌우 인접한 경우 찾기
	vector<pair<int, int>> ret; //인접한 유물 배열
	queue<pair<int, int> > q; //x, y, 인접 개수

	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		ret.push_back({ x, y });

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= tempBoard.size() || ny >= tempBoard[0].size()) continue;

			if (tempBoard[nx][ny] == num && visit[nx][ny] == false) {
				q.push({ nx, ny });
				visit[nx][ny] = true;
			}
		}
	}

	if (ret.size() <= 2) {
		ret.clear();
	}

	return ret;
}

void removeValues(int x, int y, vector<vector<int> >& rotatedBoard) {
	rotatedBoard[x][y] = -1;
}

vector<pair<int, int> > getValues(vector<vector<int> >& rotatedBoard) { //인접된 요소 위치 반환
	int curValue = 0;
	vector<vector<bool> > visit(rotatedBoard.size(), vector<bool>(rotatedBoard[0].size(), false));

	vector<pair<int, int> > removeList;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (visit[i][j] == false) {
				vector<pair<int, int> > v = bfs2(i, j, rotatedBoard[i][j], rotatedBoard, visit);

				for (int k = 0; k < v.size(); k++) {
					removeList.push_back(v[k]);
				}
			}
		}
	}

	return removeList;
}

void changeBoard(vector<vector<int> >& rotatedBoard) {
	for (int j = 0; j < 5; j++) {
		for (int i = 4; i >= 0; i--) {
			if (rotatedBoard[i][j] == -1) {
				rotatedBoard[i][j] = wall.front();
				wall.pop();
			}
		}
	}
}

void solution() {
	for (int round = 0; round < k; round++) {
		answer = 0;

		//조건에 맞는 회전 목표 찾기
		pair<pair<int, int>, int> rotatePoint = getRotatePoint(); //중심 좌표 행 열, 회전 각도

		if (rotatePoint.first.first == -1 && rotatePoint.first.second == -1 && rotatePoint.second == -1) {
			break;
		}

		//회전시키기
		vector<vector<int> > rotatedBoard = rotate(rotatePoint.first.first, rotatePoint.first.second, rotatePoint.second);

		//획득 진행
		while (1) {
			vector<pair<int, int> > values = getValues(rotatedBoard); //인접된 요소들 위치 찾기

			if (values.empty()) {
				break;
			}

			answer += values.size();

			//보드에서 -1 처리
			for (int i = 0; i < values.size(); i++) {
				removeValues(values[i].first, values[i].second, rotatedBoard);
			}

			//유물 채우기
			changeBoard(rotatedBoard);
			board = rotatedBoard;
		}

		cout << answer << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}