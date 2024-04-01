#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<int> > board, dice;
pair<int, int> location;
vector<int> direction, answer;

int dx[] = {0, 0, -1, 1}; //동서북남
int dy[] = {1, -1, 0, 0};

void input() {
	int x, y;
	cin >> n >> m >> x >> y >> k;

	board.assign(n, vector<int>(m));

	location = { x, y };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> x;
		direction.push_back(x - 1);
	}

	dice.assign(4, vector<int>(3, 0));
}

void move(int dir) {
	if (dir == 0) {
		int temp = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = temp;
	}
	else if (dir == 1) {
		int temp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = temp;
	}
	else if (dir == 2) {
		int temp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = temp;
	}
	else {
		int temp = dice[0][1];
		dice[0][1] = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = temp;
	}
}

void solution() {
	int x = location.first;
	int y = location.second;

	for (int dir : direction) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
			continue;
		}

		move(dir);

		if (board[nx][ny] == 0) {
			board[nx][ny] = dice[3][1];
		}
		else {
			dice[3][1] = board[nx][ny];
			board[nx][ny] = 0;
		}

		answer.push_back(dice[1][1]);

		x = nx;
		y = ny;
	}

	for (int n : answer) {
		cout << n << "\n";
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