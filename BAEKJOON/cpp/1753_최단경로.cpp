#include <iostream>
#include <vector>
#include <queue>

#define MAX 20001
#define INF 987654321
using namespace std;

int v, e, k;
vector<pair<int, int > > vertex[MAX];
int dist[MAX];

void input() {
	cin >> v >> e >> k;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		vertex[a].push_back({ b, c });
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

		if (dist[cur] < cost) continue;

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
	for (int i = 1; i <= v; i++) {
		dist[i] = INF;
	}

	dijkstra(k);

	for (int i = 1; i <= v; i++) {
		if (dist[i] != INF)
			cout << dist[i] << "\n";
		else
			cout << "INF\n";
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