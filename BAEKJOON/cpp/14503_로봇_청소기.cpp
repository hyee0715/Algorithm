#include <iostream>
#include <vector>
using namespace std;

struct Robot {
	int x;
	int y;
	int dir;
};

int dx[] = { 0, -1, 0, 1 }; //동 북 서 남
int dy[] = { 1, 0, -1, 0 };

int n, m;
vector<vector<int>> board; //0: 청소 안 된 빈 칸, 1: 청소 된 빈 칸, 2: 벽
Robot robot;
int answer = 0;

int changeDirection(int dir) {
	if (dir == 0) {
		return 1;
	}
	else if (dir == 1) {
		return 0;
	}
	else if (dir == 2) {
		return 3;
	}
	return 2;
}

void input() {
	cin >> n >> m;

	int a, b, c;
	cin >> a >> b >> c;

	c = changeDirection(c);

	robot = { a, b, c };

	board.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;

			if (a == 1) {
				a = 2;
			}

			board[i][j] = a;
		}
	}
}

void settingRobot() {
	int x = robot.x;
	int y = robot.y;
	
	board[x][y] = 1;
	answer++;
}

void cleanCurrentSpace() {
	int x = robot.x;
	int y = robot.y;

	if (board[x][y] == 0) {
		board[x][y] = 1;
		answer++;
	}
}

bool checkNeighborSpace() {
	//주변 4칸 중에 청소되지 않은 빈칸이 있으면 true 리턴, 없으면 false 리턴
	int x = robot.x;
	int y = robot.y;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size() || board[nx][ny] == 2) {
			continue;
		}

		if (board[nx][ny] == 0) {
			return true;
		}
	}

	return false;
}

void solution() {
	//로봇 첫 칸 세팅
	settingRobot();

	while (1) {
		//현재 칸이 청소되지 않았으면 현재 칸 청소
		cleanCurrentSpace();

		if (checkNeighborSpace()) {
			//청소되지 않은 빈 칸이 있는 경우
			int x = robot.x;
			int y = robot.y;
			int dir = robot.dir;

			for (int i = 1; i <= 4; i++) {
				int ndir = (dir + i) % 4;
				int nx = x + dx[ndir];
				int ny = y + dy[ndir];

				if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size() || board[nx][ny] == 2) {
					continue;
				}

				if (board[nx][ny] == 0) {
					robot.x = nx;
					robot.y = ny;
					robot.dir = ndir;
					break;
				}
			}
		}
		else {
			//청소되지 않은 빈 칸이 없는 경우
			int x = robot.x;
			int y = robot.y;
			int dir = robot.dir;

			//후진하기
			int nx = x + dx[((dir + 2) % 4)];
			int ny = y + dy[((dir + 2) % 4)];

			if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size() || board[nx][ny] == 2) {
				break;
			}

			robot.x = nx;
			robot.y = ny;
		}
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