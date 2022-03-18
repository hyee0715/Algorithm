#include <iostream>
#include <cstring>

#define MAX 50
using namespace std;

int n, m, cnt = 0;
char map[MAX][MAX];
bool visit[MAX][MAX];

int row_dx[] = { 0, 0 }; // 동, 서
int	row_dy[] = { 1, -1 };
int col_dx[] = { 1, -1 }; // 남, 북
int col_dy[] = { 0, 0 };

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void row_dfs(int x, int y) {
	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + row_dx[i];
		int ny = y + row_dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		if (map[nx][ny] == '-' && visit[nx][ny] == false) {
			row_dfs(nx, ny);
		}
	}
}

void col_dfs(int x, int y) {
	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + col_dx[i];
		int ny = y + col_dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		if (map[nx][ny] == '|' && visit[nx][ny] == false) {
			col_dfs(nx, ny);
		}
	}
}

void solution() {
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '-' && visit[i][j] == false) {
				cnt++;
				row_dfs(i, j);
			}

			if (map[i][j] == '|' && visit[i][j] == false) {
				cnt++;
				col_dfs(i, j);
			}
		}
	}

	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}