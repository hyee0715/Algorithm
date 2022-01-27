#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 51
using namespace std;

int m, n, k;
int map[MAX][MAX];
bool visit[MAX][MAX];
vector<int> answer;
int cnt;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visit[x][y] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (map[nx][ny] == 1 && visit[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					visit[nx][ny] = true;
				}
			}
		}
	}
}

void solution() {
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visit[i][j] == false) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	answer.push_back(cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		cnt = 0;

		cin >> m >> n >> k;

		int a, b;
		for (int j = 0; j < k; j++) {
			cin >> a >> b;
			map[b][a] = 1;
		}

		solution();
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}