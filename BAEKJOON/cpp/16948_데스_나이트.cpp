#include <iostream>
#include <cstring>
#include <queue>

#define MAX 200
using namespace std;

int n, r1, r2, c1, c2, cnt = 0;
bool visit[MAX][MAX];

int dx[] = { -2, -2, 0, 0, 2, 2 };
int dy[] = { -1, 1, -2, 2, -1, 1 };

void input() {
	cin >> n >> r1 >> c1 >> r2 >> c2;
}

void bfs(int a, int b, int cnt) {
	queue<pair<pair<int, int>, int> > q;
	visit[a][b] = true;
	q.push(make_pair(make_pair(a, b), cnt));

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int answer = q.front().second;
		q.pop();

		if (x == r2 && y == c2) {
			cout << answer;
			return;
		}

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (visit[nx][ny] == false) {
					visit[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), answer + 1));
				}
			}
		}
	}

	cout << "-1";
}

void solution() {
	memset(visit, false, sizeof(visit));

	bfs(r1, c1, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}