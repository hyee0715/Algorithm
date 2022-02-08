#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 101
using namespace std;

int m, n, k;
int map[MAX][MAX];
bool visit[MAX][MAX];
vector<int> answer;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void input() {
	memset(map, 0, sizeof(map));
	memset(visit, false, sizeof(visit));

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;

		for (int j = ly; j < ry; j++) {
			for (int k = lx; k < rx; k++) {
				map[j][k] = 1;
			}
		}
	}
}

void bfs(int a, int b) {
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	visit[a][b] = true;
	int cnt = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
				if (map[nx][ny] == 0 && visit[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					visit[nx][ny] = true;
				}
			}
		}
	}

	answer.push_back(cnt);
}

void solution() {
	/*for (int j = 0; j < m; j++) {
		for (int k = 0; k < n; k++) {
			cout << map[j][k] << " ";
		}
		cout << endl;
	}*/

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && visit[i][j] == false) {
				bfs(i, j);
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}