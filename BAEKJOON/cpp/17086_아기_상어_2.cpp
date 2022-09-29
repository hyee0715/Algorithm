#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, max_num = -1;
vector<vector<int>> map;
vector<vector<bool>> visit;

int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1};

void input() {
	cin >> n >> m;

	map.assign(n, vector<int>(m));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

int bfs(int a, int b) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a, b}, 1 });
	visit[a][b] = true;
	
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (map[nx][ny] == 0 && visit[nx][ny] == false) {
				q.push({ {nx, ny}, cnt + 1 });
				visit[nx][ny] = true;
			}
			else if (map[nx][ny] == 1) {
				return cnt;
			}
		}
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				visit.assign(n, vector<bool>(m, false));
				max_num = max(max_num, bfs(i, j));
			}
		}
	}

	cout << max_num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solution();

	return 0;
}