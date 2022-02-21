#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define MAX 100
using namespace std;

int n, maxNum, cnt, answer;
int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

int findMaxOfArr() {
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cnt < map[i][j]) {
				cnt = map[i][j];
			}
		}
	}

	return cnt;
}

void bfs(int a, int b, int c) { // a: xÁÂÇ¥, b: yÁÂÇ¥, c: ºñÀÇ ¾ç
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	visit[a][b];

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (map[nx][ny] > c && visit[nx][ny] == false) {
					visit[nx][ny] = true;
					bfs(nx, ny, c);
				}
			}
		}
	}
}

void solution() {
	maxNum = findMaxOfArr();

	for (int k = 0; k <= maxNum; k++) {
		memset(visit, false, sizeof(visit));
		cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > k && visit[i][j] == false) {
					cnt++;
					bfs(i, j, k);
				}
			}
		}

		answer = max(answer, cnt);
;	}

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