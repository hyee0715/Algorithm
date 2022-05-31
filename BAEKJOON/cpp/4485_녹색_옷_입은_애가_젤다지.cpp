#include <iostream>
#include <queue>
#include <cstring>

#define MAX 125
#define INF 987654321
using namespace std;

int n, answer_cnt = 1;
int map[MAX][MAX], dist[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

void dijkstra(int a, int b) {
	priority_queue<pair<int, pair<int, int> > > pq;
	pq.push({ -map[a][b], {a, b} });
	dist[a][b] = map[a][b];

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (dist[x][y] < cost) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			int n_cost = map[nx][ny];

			if (dist[nx][ny] > cost + n_cost) {
				dist[nx][ny] = cost + n_cost;
				pq.push({ -dist[nx][ny], {nx, ny} });
			}
		}
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
		}
	}

	dijkstra(0, 0);

	cout << "Problem " << answer_cnt++ << ": " << dist[n - 1][n - 1] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> n;

		if (n == 0)
			break;
	
		input();
		solution();
	}

	return 0;
}