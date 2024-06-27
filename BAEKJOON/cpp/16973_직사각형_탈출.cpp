#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int> > board;
vector<pair<int, int> > walls;
pair<int, int> squareSize, start, goal;

int dx[] = {0, 0, 1, -1};
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m;

	board.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

			if (board[i][j] == 1) {
				walls.push_back({ i, j });
			}
		}
	}

	int a, b;
	cin >> a >> b;
	squareSize = { a, b };

	cin >> a >> b;
	start = { a - 1, b - 1};

	cin >> a >> b;
	goal = { a - 1, b - 1};
}

bool check(int nx, int ny) {
	if (nx < 0 || ny < 0 || nx >= n || ny >= m) return false;;

	if (nx + squareSize.first - 1 >= n || ny + squareSize.second - 1 >= m) return false;;

	for (int i = 0; i < walls.size(); i++) {
		int wx = walls[i].first;
		int wy = walls[i].second;

		if (nx <= wx && nx + squareSize.first - 1 >= wx && ny <= wy && ny + squareSize.second - 1 >= wy) {
			return false;
		}
	}

	return true;
}

int bfs(int a, int b) {
	vector<vector<bool> > visit(n, vector<bool>(m, false));
	queue<pair<pair<int, int>, int> > q; //x, y, cnt

	q.push({ {a, b}, 0 });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == goal.first && y == goal.second) {
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!check(nx, ny)) {
				continue;
			}

			if (visit[nx][ny] == false) {
				q.push({ {nx, ny}, cnt + 1 });
				visit[nx][ny] = true;
			}
		}
	}

	return -1;
}

void solution() {
	cout << bfs(start.first, start.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}