#include <iostream>
#include <queue>
#include <vector>

#define MAX 1001
#define INF 987654321
using namespace std;

int n, m, start_city, end_city;
vector<pair<int, int> > vertex[MAX];
int dist[MAX];

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		vertex[a].push_back(make_pair(b, c));
	}

	cin >> start_city >> end_city;
}

void dijkstra() {
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start_city));
	dist[start_city] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0; i < vertex[cur].size(); i++) {
			int next = vertex[cur][i].first;
			int nCost = vertex[cur][i].second;

			if (dist[next] > cost + nCost) {
				dist[next] = cost + nCost;

				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}

void solution() {
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	dijkstra();

	cout << dist[end_city];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}