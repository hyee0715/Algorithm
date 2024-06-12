#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

struct Golem {
	int num;
	int x; //중앙 자리 좌표 x
	int y; //중앙 자리 좌표 y
	int exitDir; //출구 방향 정보
};

int r, c, k; //r: 격자 행, c: 격자 열, k: 정령의 수
vector<pair<int, int> > orders; //골렘이 출발하는 열, 골렘의 출구 방향 정보
vector<vector<int> > board;
map<int, Golem> golemMap;
int answer;

int dx[] = { -1, 0, 1, 0 }; //북동남서
int dy[] = { 0, 1, 0, -1 };

void input() {
	cin >> r >> c >> k;

	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;

		orders.push_back({ a - 1, b });
	}
}

void setGolemToBoard(int num) {
	Golem golem = golemMap[num];
	int x = golem.x;
	int y = golem.y;

	board[x][y] = num;
	board[x - 1][y] = num;
	board[x + 1][y] = num;
	board[x][y - 1] = num;
	board[x][y + 1] = num;
}

bool validateSouth(int row, int col) { //아래 세 칸으로 이동 가능한지 확인. 가능하면 true 리턴, 가능하지 않으면 false 리턴
	vector<vector<int> > spaces = { {row + 1, col - 1}, {row + 2, col}, {row + 1, col + 1} };

	for (vector<int> space : spaces) {
		int nx = space[0];
		int ny = space[1];

		if (nx < 0 || ny < 0 || nx >= r + 3 || ny >= c) {
			return false;
		}

		if (board[nx][ny] != 0) {
			return false;
		}
	}

	return true;
}

pair<pair<int, int>, int> moveSouth(int row, int col, int exitDir) { //이동 가능한 남쪽 위치 리턴, 가능하지 않으면 원래 중심 자리 리턴
	int r = row;
	int c = col;

	bool result = validateSouth(r, c);
	while (result) {
		r = r + 1;
		result = validateSouth(r, c);
	}

	return { {r, c}, exitDir };
}

bool validateWest(int row, int col) { //아래 남서쪽으로 이동 가능한지 확인. 가능하면 true 리턴, 가능하지 않으면 false 리턴
	vector<vector<int> > spaces = { {row - 1, col - 1}, {row, col - 2}, {row + 1, col - 2}, {row + 1, col - 1}, {row + 2, col - 1} };

	for (vector<int> space : spaces) {
		int nx = space[0];
		int ny = space[1];

		if (nx < 0 || ny < 0 || nx >= r + 3 || ny >= c) {
			return false;
		}

		if (board[nx][ny] != 0) {
			return false;
		}
	}

	return true;
}

pair<pair<int, int>, int> moveWest(int row, int col, int exitDir) { //이동 가능한 남서쪽 위치 리턴, 가능하지 않으면 원래 중심 자리 리턴
	int r = row;
	int c = col;
	int dir = exitDir;

	bool result = validateWest(r, c);
	while (result) {
		r = r + 1;
		c = c - 1;
		dir = dir - 1;

		if (dir < 0) {
			dir = 3;
		}

		pair<pair<int, int>, int> location = moveSouth(r, c, dir);
		r = location.first.first;
		c = location.first.second;
		dir = location.second;

		result = validateWest(location.first.first, location.first.second);
	}

	return { {r, c}, dir };
}

bool validateEast(int row, int col) { //아래 남동쪽으로 이동 가능한지 확인. 가능하면 true 리턴, 가능하지 않으면 false 리턴
	vector<vector<int> > spaces = { {row - 1, col + 1}, {row, col + 2}, {row + 1, col + 1}, {row + 1, col + 2}, {row + 2, col + 1} };

	for (vector<int> space : spaces) {
		int nx = space[0];
		int ny = space[1];

		if (nx < 0 || ny < 0 || nx >= r + 3 || ny >= c) {
			return false;
		}

		if (board[nx][ny] != 0) {
			return false;
		}
	}

	return true;
}

pair<pair<int, int>, int> moveEast(int row, int col, int exitDir) { //이동 가능한 남동쪽 위치 리턴, 가능하지 않으면 원래 중심 자리 리턴
	int r = row;
	int c = col;
	int dir = exitDir;

	bool result = validateEast(r, c);
	while (result) {
		r = r + 1;
		c = c + 1;
		dir = (dir + 1) % 4;

		pair<pair<int, int>, int> location = moveSouth(r, c, dir);
		r = location.first.first;
		c = location.first.second;
		dir = location.second;

		result = validateEast(location.first.first, location.first.second);
	}

	return { {r, c}, dir };
}

bool checkBoundary() {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] != 0) {
				return false;
			}
		}
	}

	return true;
}

bool moveGolem(int golemNum, int golemCol, int golemExitDir) {
	int golemRow = 1;
	pair<pair<int, int>, int> location = moveSouth(golemRow, golemCol, golemExitDir);

	location = moveWest(location.first.first, location.first.second, location.second);

	location = moveEast(location.first.first, location.first.second, location.second);

	Golem golem = { golemNum, location.first.first, location.first.second, location.second };
	golemMap[golemNum] = golem;

	setGolemToBoard(golemNum);

	return checkBoundary(); //골렘 움직임이 끝났을 때 격자 범위 벗어나면 false 리턴, 벗어나지 않으면 true 리턴
}

int moveSpirit(int golemNum) {
	int cx = golemMap[golemNum].x;
	int cy = golemMap[golemNum].y;

	int maxRow = 0;

	map<int, bool> visit; //골렘 번호, 방문 여부
	queue<pair<int, int> > q; //현재 골렘 중심 좌표 x, y

	q.push({ cx, cy });
	visit[golemNum] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int curNum = board[x][y];
		int curExitDir = golemMap[curNum].exitDir;
		x = golemMap[curNum].x;
		y = golemMap[curNum].y;

		maxRow = max(maxRow, x + 1);

		int exitX = x + dx[curExitDir];
		int exitY = y + dy[curExitDir];

		for (int i = 0; i < 4; i++) {
			int nx = exitX + dx[i];
			int ny = exitY + dy[i];

			if (nx < 0 || ny < 0 || nx >= r + 3 || ny >= c || board[nx][ny] == curNum) {
				continue;
			}

			if (board[nx][ny] != 0 && visit[board[nx][ny]] == false) {
				visit[board[nx][ny]] = true;
				q.push({ nx, ny });
			}
		}
	}

	return maxRow;
}

void solution() {
	answer = 0;
	board.assign(r + 3, vector<int>(c, 0));

	for (int round = 0; round < k; round++) {
		int golemCol = orders[round].first; //골렘이 출발하는 열
		int golemExitDir = orders[round].second; //골렘의 출구 방향 정보
		int golemNum = round + 1;

		bool result = moveGolem(golemNum, golemCol, golemExitDir); //골렘 움직임 시작

		if (!result) { //격자 벗어나면 비우고 다시 시작
			board.clear();
			board.assign(r + 3, vector<int>(c, 0));

			continue;
		}

		int maxRow = moveSpirit(golemNum) - 2;
		answer += maxRow;
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}