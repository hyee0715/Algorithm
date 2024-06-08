#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

struct Golem {
	int num;
	int exitDir;
	pair<int, int> center;
};

int dx[] = { -1, 0, 1, 0 }; //북동남서
int dy[] = { 0, 1, 0, -1 };

int r, c, k; //r,c : 숲 크기 , k : 정령의 수
vector<pair<int, int> > orders; //골렘이 출발하는 열, 골렘의 출구 방향 정보 (0123, 북동남서)
vector<vector<int> > board;
unordered_map<int, Golem> golemMap; //골렘 번호, 골렘

int tempMax;

void input() {
	cin >> r >> c >> k;

	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;

		orders.push_back({ a - 1, b });
	}
}

Golem validateSouth(Golem golem) {
	int initialRow = golem.center.first;
	int initialCol = golem.center.second;

	if (initialRow == -1) { //처음 이동
		vector<pair<int, int> > v = { {1, initialCol}, {1, initialCol - 1}, {1, initialCol + 1}, {0, initialCol}, {2, initialCol} };

		for (pair<int, int> p : v) {
			int row = p.first;
			int col = p.second;

			if (row < 0 || col < 0 || row >= r + 3 || col >= c) {
				return golem;
			}

			if (board[row][col] != 0) {
				return golem;
			}
		}

		golem.center = { 1, initialCol };
		return golem;
	}
	else { //중간부터 이동
		int centerRow = golem.center.first;
		int centerCol = golem.center.second;
		vector<pair<int, int> > v = { {centerRow + 1, centerCol - 1}, {centerRow + 2, centerCol}, {centerRow + 1, centerCol + 1} };

		for (pair<int, int> p : v) {
			int row = p.first;
			int col = p.second;

			if (row < 0 || col < 0 || row >= r + 3 || col >= c) {
				return golem;
			}

			if (board[row][col] != 0) {
				return golem;
			}
		}

		golem.center = { centerRow + 1, centerCol };
		return golem;
	}
}

Golem validateWest(Golem golem) { //서남쪽으로 이동 가능한지 체크
	int centerRow = golem.center.first;
	int centerCol = golem.center.second;
	vector<pair<int, int> > v = { {centerRow - 1, centerCol - 1}, {centerRow, centerCol - 2}, {centerRow + 1, centerCol - 1}, {centerRow + 1, centerCol - 2}, {centerRow + 2, centerCol - 1} };

	for (pair<int, int> p : v) {
		int row = p.first;
		int col = p.second;

		if (row < 0 || col < 0 || row >= r + 3 || col >= c) {
			return golem;
		}

		if (board[row][col] != 0) {
			return golem;
		}
	}

	golem.center = { centerRow + 1, centerCol - 1 };
	return golem;
}

Golem validateEast(Golem golem) { //동남쪽으로 이동 가능한지 체크
	int centerRow = golem.center.first;
	int centerCol = golem.center.second;
	vector<pair<int, int> > v = { {centerRow - 1, centerCol + 1}, {centerRow, centerCol + 2}, {centerRow + 1, centerCol + 1}, {centerRow + 1, centerCol + 2}, {centerRow + 2, centerCol + 1} };

	for (pair<int, int> p : v) {
		int row = p.first;
		int col = p.second;

		if (row < 0 || col < 0 || row >= r + 3 || col >= c) {
			return golem;
		}

		if (board[row][col] != 0) {
			return golem;
		}
	}

	golem.center = { centerRow + 1, centerCol + 1 };
	return golem;
}

void saveGolem(Golem golem) {
	int num = golem.num;

	int row = golem.center.first;
	int col = golem.center.second;

	vector<pair<int, int>> v = { {row, col}, {row - 1, col}, {row + 1, col}, {row, col - 1}, {row, col + 1} };

	for (pair<int, int> p : v) {
		int nr = p.first;
		int nc = p.second;

		board[nr][nc] = num;
	}
}

void moveSouth(Golem golem) {
	Golem validatedGolem = validateSouth(golem);

	while (!((golem.center.first == validatedGolem.center.first) && (golem.center.second == validatedGolem.center.second))) { //이동 가능하면 남쪽으로 한 칸 이동
		golemMap[golem.num] = validatedGolem;
		golem = validatedGolem;

		validatedGolem = validateSouth(golemMap[golem.num]);
	}
}

void moveWest(Golem golem) {
	Golem validatedGolem = validateWest(golem);

	while (!((golem.center.first == validatedGolem.center.first) && (golem.center.second == validatedGolem.center.second))) { //이동 가능하면 서남쪽으로 한 칸 이동, 출구 방향도 바꾸기
		golem = validatedGolem;
		golemMap[golem.num] = validatedGolem;

		moveSouth(validatedGolem);

		int dir = golemMap[golem.num].exitDir - 1;

		if (dir == -1) {
			dir = 3;

		}
		golemMap[golem.num].exitDir = dir;

		golem = golemMap[golem.num];
		validatedGolem = validateWest(golemMap[golem.num]);
	}
}

void moveEast(Golem golem) {
	Golem validatedGolem = validateEast(golem);

	while (!((golem.center.first == validatedGolem.center.first) && (golem.center.second == validatedGolem.center.second))) { //이동 가능하면 동남쪽으로 한 칸 이동, 출구 방향도 바꾸기
		golem = validatedGolem;
		golemMap[golem.num] = validatedGolem;

		moveSouth(validatedGolem);

		int dir = (golemMap[golem.num].exitDir + 1) % 4;
		golemMap[golem.num].exitDir = dir;

		golem = golemMap[golem.num];
		validatedGolem = validateEast(golemMap[golem.num]);
	}
}

bool validateOutSpace(Golem golem) { //골렘이 범위 밖을 나가면 false 리턴
	int row = golem.center.first;
	int col = golem.center.second;

	vector<pair<int, int>> v = { {row, col}, {row, col - 1}, {row, col + 1}, {row - 1, col}, {row + 1, col} };

	for (pair<int, int> p : v) {
		int pr = p.first;
		int pc = p.second;

		if (pr <= 2) {
			return false;
		}
	}

	return true;
}

bool moveGolem(Golem golem) {
	moveSouth(golem);

	golem = golemMap[golem.num];
	moveWest(golem);

	golem = golemMap[golem.num];
	moveEast(golem);

	golem = golemMap[golem.num];

	if (!validateOutSpace(golem)) {
		return false;
	}

	saveGolem(golem);
	return true;
}

pair<int, int> getExitPair(int golemNum) {
	Golem golem = golemMap[golemNum];
	pair<int, int> ret = { -1, -1 };

	int row = golem.center.first;
	int col = golem.center.second;

	int dir = golem.exitDir;

	if (dir == 0) {
		ret = { row - 1, col };
	}
	else if (dir == 1) {
		ret = { row, col + 1 };
	}
	else if (dir == 2) {
		ret = { row + 1, col };
	}
	else {
		ret = { row, col - 1 };
	}

	return ret;
}

int getDownLocation(int golemNum) {
	Golem golem = golemMap[golemNum];

	int row = golem.center.first;
	int col = golem.center.second;

	return row + 1 - 2;
}

void moveSpirit(int golemNum) { //나갈 때는 반드시 출구로, 들어갈 때는 아무 곳이나 가능, 골렘에 들어오면 그 골렘의 가장 아랫부분 갱신, 출구로 이동해서 상하좌우 움직이기
	Golem golem = golemMap[golemNum];

	unordered_map<int, bool> visit;
	queue<pair<int, int> > q;

	pair<int, int> exit = getExitPair(golemNum);
	visit[golemNum] = true;
	q.push({ exit.first, exit.second });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int curNum = board[x][y];
		q.pop();

		//가장아래 행 찾기
		int downRow = getDownLocation(curNum);
		tempMax = max(tempMax, downRow);

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 3 || ny < 0 || nx >= r + 3 || ny >= c) {
				continue;
			}

			if (board[nx][ny] != 0 && visit[board[nx][ny]] == false) {
				visit[board[nx][ny]] = true;

				pair<int, int> exit = getExitPair(board[nx][ny]);
				q.push({ exit.first, exit.second });
			}
		}
	}
}

void solution() {
	int answer = 0;
	board.assign(r + 3, vector<int>(c, 0));

	for (int i = 0; i < orders.size(); i++) {
		tempMax = 0;

		int golemNum = i + 1;
		int startCol = orders[i].first;
		int exitDir = orders[i].second;

		Golem golem = { golemNum, exitDir, { -1, startCol } };
		golemMap[golemNum] = golem;

		if (!moveGolem(golem)) {
			board.clear();
			board.assign(r + 3, vector<int>(c, 0));

			golemMap.erase(golemNum);
		}
		else {
			moveSpirit(golemNum);
		}

		answer += tempMax;
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