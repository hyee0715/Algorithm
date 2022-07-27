#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<vector<int>> map;
vector<vector<int>> dp(500, vector<int>(500, -1));

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		vector<int> v;

		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;

			v.push_back(a);
		}

		map.push_back(v);
	}
}

int dfs(int x, int y) {
	if (x == m - 1 && y == n - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

		if (map[x][y] > map[nx][ny]) {
			dp[x][y] = dp[x][y] + dfs(nx, ny);
		}
	}

	return dp[x][y];
}

void solution() {
	cout << dfs(0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}