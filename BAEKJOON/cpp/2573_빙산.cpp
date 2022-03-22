#include <iostream>
#include <queue>
#include <cstring>

#define MAX 300
using namespace std;

int n, m, cnt, zero_count, answer = 0;
int map[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<pair<int, int>, int> > new_q; // 녹을 빙산의 x좌표, y좌표, 갱신될 빙산 값

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void bfs(int a, int b) {
	queue<pair<int, int> > q;
	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		zero_count = 0;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (map[nx][ny] == 0) {
				zero_count++;
			}

			if (map[nx][ny] != 0 && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}

		new_q.push({ {x, y}, map[x][y] - zero_count });
	}
}

bool all_melted() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0)
				return false;
		}
	}

	return true;
}

void solution() {
	while (1) {
		cnt = 0;
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0 && visit[i][j] == false) { // 빙산이 두 덩어리인지 확인하면서, 0이 아닌 값들 중에 주변에 0이 몇개 있는지 센다.
					cnt++;
					bfs(i, j);
				}
			}
		}

		//만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.
		if (all_melted() && cnt == 0) {
			cout << "0";
			return;
		}

		if (cnt == 1) { //빙산이 한 덩어리라면 빙산 녹이기
			while (!new_q.empty()) {
				int x = new_q.front().first.first;
				int y = new_q.front().first.second;
				int iceberg = new_q.front().second;

				if (iceberg < 0)
					iceberg = 0;

				map[x][y] = iceberg;
				new_q.pop();
			}
		}
		else {
			cout << answer;
			break;
		}

		answer++;
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