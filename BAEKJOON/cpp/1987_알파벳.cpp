#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#define MAX 20
using namespace std;

int r, c;
char map[MAX][MAX];
bool visit[MAX][MAX];
bool alphabet[26];
int cnt = 0, answer = 0;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> r >> c;

	string s;

	for (int i = 0; i < r; i++) {
		cin >> s;

		for (int j = 0; j < c; j++) {
			map[i][j] = s[j];
		}
	}
}

void dfs(int x, int y) {
	visit[x][y] = true;
	alphabet[map[x][y] - 'A'] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
			if (alphabet[map[nx][ny] - 'A'] == false && visit[nx][ny] == false) {
				dfs(nx, ny);
				alphabet[map[nx][ny] - 'A'] = false;
				visit[nx][ny] = false;
				cnt--;
			}
		}
	}

	answer = max(answer, cnt);
}

void solution() {
	memset(visit, false, sizeof(visit));
	memset(alphabet, false, sizeof(alphabet));

	dfs(0, 0);

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