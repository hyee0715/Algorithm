#include <iostream>
#include <queue>
#include <vector>

#define MAX 50001
#define INF 987654321
using namespace std;

int n, m;
vector<pair<int, int> > vertex[MAX];
int dist[MAX];

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		vertex[a].push_back({ b, c });
		vertex[b].push_back({ a, c });
	}
}

void dijkstra(int start) {
	priority_queue<pair<int, int> > pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (int i = 0; i < vertex[cur].size(); i++) {
			int next = vertex[cur][i].first;
			int n_cost = vertex[cur][i].second;

			if (dist[next] > cost + n_cost) {
				dist[next] = cost + n_cost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

void solution() {
	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	dijkstra(1);

	cout << dist[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}