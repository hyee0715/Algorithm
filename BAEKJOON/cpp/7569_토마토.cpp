#include <iostream>
#include <cstring>
#include <queue>

#define MAX 100
using namespace std;

int m, n, h, cnt = 0;
int map[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
queue<pair<pair<int, int>, int> > q;

int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

void input() {
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> map[j][k][i];

				if (map[j][k][i] == 1) {
					q.push({ {j, k}, i });
					visit[j][k][i] = true;
				}
			}
		}
	}
}

bool is_all_ripe() { //모두 익었다면 true, 익지 않은 것이 있다면 false 반환
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[j][k][i] == 0)
					return false;
			}
		}
	}

	return true;
}

void bfs() {
	while (!q.empty()) {
		int q_size = q.size();

		for (int k = 0; k < q_size; k++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int z = q.front().second;
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;

				if (map[nx][ny][nz] == 0 && visit[nx][ny][nz] == false) {
					q.push({ {nx, ny}, nz });
					map[nx][ny][nz] = 1;
					visit[nx][ny][nz] = true;
				}
			}
		}

		cnt++;

		if (is_all_ripe()) {
			return;
		}
	}
}

void solution() {
	if (is_all_ripe()) { //저장될 때 부터 모든 토마토가 익어있으면 0을 출력
		cout << "0";
		return;
	}

	bfs();

	if (!is_all_ripe()) //모두 익어있는지 다시 한 번 확인한 후, 모든 토마토가 익지 못했으면 -1 출력
		cout << "-1";
	else //모두 익었다면 최소 일 수 출력
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