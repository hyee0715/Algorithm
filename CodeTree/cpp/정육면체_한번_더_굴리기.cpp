#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Dice {
	int x;
	int y;
	int direction;
	int score;
	vector<vector<int> > status;
};

int n, m;
vector<vector<int> > board;
Dice dice;

int dx[] = { -1, 0, 1, 0 }; //북동남서
int dy[] = { 0, 1, 0, -1 };

void input() {
	cin >> n >> m;

	board.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

vector<vector<int> > initializeDiceStatus() {
	vector<vector<int> > dc(4, vector<int>(3, 0));

	dc[0][1] = 5;
	dc[1][0] = 4;
	dc[1][1] = 1;
	dc[1][2] = 3;
	dc[2][1] = 2;
	dc[3][1] = 6;

	return dc;
}

void rotateDice(int direction) {
	if (direction == 0) { //북
		int temp = dice.status[0][1];
		dice.status[0][1] = dice.status[1][1];
		dice.status[1][1] = dice.status[2][1];
		dice.status[2][1] = dice.status[3][1];
		dice.status[3][1] = temp;
	}
	else if (direction == 1) { //동
		int temp = dice.status[1][2];
		dice.status[1][2] = dice.status[1][1];
		dice.status[1][1] = dice.status[1][0];
		dice.status[1][0] = dice.status[3][1];
		dice.status[3][1] = temp;
	}
	else if (direction == 2) { //남
		int temp = dice.status[3][1];
		dice.status[3][1] = dice.status[2][1];
		dice.status[2][1] = dice.status[1][1];
		dice.status[1][1] = dice.status[0][1];
		dice.status[0][1] = temp;
	}
	else { //서
		int temp = dice.status[1][0];
		dice.status[1][0] = dice.status[1][1];
		dice.status[1][1] = dice.status[1][2];
		dice.status[1][2] = dice.status[3][1];
		dice.status[3][1] = temp;
	}
}

void initializeDice() {
	vector<vector<int> > dc = initializeDiceStatus();

	dice = { 0, 0, 1, 0, dc };
}

void moveDice() {
	int x = dice.x;
	int y = dice.y;
	int dir = dice.direction;

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	dice.x = nx;
	dice.y = ny;

	rotateDice(dir);
}

int getNeighborSpaceCount(int a, int b) {
	//(a, b)와 동일한 점수를 가진 칸 개수 구하기
	int count = 0;

	vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));
	queue<pair<int, int> > q;
	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		count++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
				continue;
			}

			if (board[nx][ny] == board[a][b] && visit[nx][ny] == false) {
				q.push({ nx, ny });
				visit[nx][ny] = true;
			}
		}
	}

	return count;
}

void renewDiceDirection() {
	int diceUnderSpace = dice.status[3][1];
	int boardNum = board[dice.x][dice.y];

	int nx = dice.x;
	int ny = dice.y;
	int ndir = dice.direction;

	if (diceUnderSpace > boardNum) {
		ndir = (ndir + 1) % 4;
		nx = nx + dx[ndir];
		ny = ny + dy[ndir];
	}
	else if (diceUnderSpace < boardNum) {
		ndir = ndir - 1;
		if (ndir == -1) {
			ndir = 3;
		}
		nx = nx + dx[ndir];
		ny = ny + dy[ndir];
	}
	else {
		nx = nx + dx[ndir];
		ny = ny + dy[ndir];
	}

	if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
		ndir = (ndir + 2) % 4;
	}

	dice.direction = ndir;
}

void solution() {
	initializeDice();

	for (int turn = 1; turn <= m; turn++) {
		moveDice();

		int count = getNeighborSpaceCount(dice.x, dice.y);

		dice.score += (board[dice.x][dice.y] * count);

		renewDiceDirection();
	}

	cout << dice.score;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}