#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321
using namespace std;

int n;
vector<vector<int>> map;
vector<vector<bool>> visit;
queue<pair<int, int>> q1, q2;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		vector<int> v;

		for (int j = 0; j < n; j++) {
			cin >> a;

			v.push_back(a);
		}

		map.push_back(v);
	}
}

void bfs_land_numbering(int a, int b, int num) {
	queue<pair<int, int>> q;
	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		map[x][y] = num;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (map[nx][ny] == 1 && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

void set_land_number() {
	int num = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j] == false) {
				bfs_land_numbering(i, j, num);
				num++;
			}
		}
	}
}

int bfs(int a, int b, int c) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a, b}, c });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (map[nx][ny] == 0 && visit[nx][ny] == false) { //0이고 방문하지 않았다면 큐에 삽입
				visit[nx][ny] = true;
				q.push({ {nx, ny}, cnt + 1 });
			}

			if (map[nx][ny] != 0 && map[nx][ny] != map[a][b] && visit[nx][ny] == false) { //숫자가 다른 섬에 도착했다면 BFS 종료
				return cnt;
			}
		}
	}

	return INF;
}

void solution() {
	visit.assign(100, vector<bool>(100, false));

	set_land_number(); // 각 섬 마다 숫자를 따로 붙인다.

	visit.assign(100, vector<bool>(100, false));
	int min_num = INF;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0 && visit[i][j] == false) {

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

					if (map[nx][ny] == 0) { //동서남북 중 주변 한 곳이라도 0이면 bfs 실행
						visit.assign(100, vector<bool>(100, false));
						int cnt = 0;

						min_num = min(min_num, bfs(i, j, cnt));

						break;
					}
				}
			}
		}
	}

	cout << min_num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}