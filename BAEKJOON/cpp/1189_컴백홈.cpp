#include <iostream>
#include <cstring>
#include <string>

#define MAX 5
using namespace std;

int r, c, k, answer = 0;
char map[MAX][MAX];
bool visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> r >> c >> k;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < c; j++) {
			map[i][j] = s[j];
		}
	}
}

void dfs(int x, int y, int cnt) {
	if (x == 0 && y == c - 1) {
		if (cnt == k)
			answer++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;

		if (map[nx][ny] != 'T' && visit[nx][ny] == false) {
			visit[nx][ny] = true;
			dfs(nx, ny, cnt + 1);
			visit[nx][ny] = false;
		}
	}
}

void solution() {
	memset(visit, false, sizeof(visit));

	visit[r - 1][0] = true;
	dfs(r - 1, 0, 1);

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