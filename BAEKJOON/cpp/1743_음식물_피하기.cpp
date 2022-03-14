#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 101
using namespace std;

int n, m, k, answer = 0, sum = 0;
int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
	}
}

void dfs(int x, int y) {
	visit[x][y] = true;
	sum++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx >= 1 && ny >= 1 && nx <= n && ny <= m) {
			if (map[nx][ny] == 1 && visit[nx][ny] == false) {
				dfs(nx, ny);
			}
		}
	}

	answer = max(answer, sum);
}

void solution() {
	memset(visit, false, sizeof(visit));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1 && visit[i][j] == false) {
				sum = 0;
				dfs(i, j);
			}
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