#include <iostream>
#include <string>
#include <cstring>

#define MAX 250
using namespace std;

int r, c, sheep, wolf;
char map[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> answer = { 0, 0 }; // ¾ç, ´Á´ë ¼ö

int dx[] = { 0, 0, 1, -1 };
int dy[] = {-1, 1, 0, 0 };

void input() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < c; j++) {
			map[i][j] = s[j];
		}
	}
}

void dfs(int x, int y) {
	visit[x][y] = true;

	if (map[x][y] == 'v') {
		wolf++;
	}
	else if (map[x][y] == 'o') {
		sheep++;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (map[nx][ny] != '#' && visit[nx][ny] == false) {
			dfs(nx, ny);
		}
	}
}

void solution() {
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if ((map[i][j] == 'v' || map[i][j] == 'o') && visit[i][j] == false) {
				sheep = 0;
				wolf = 0;

				dfs(i, j);

				if (sheep > wolf) {
					answer.first += sheep;
				}
				else {
					answer.second += wolf;
				}
			}
		}
	}

	cout << answer.first << " " << answer.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}