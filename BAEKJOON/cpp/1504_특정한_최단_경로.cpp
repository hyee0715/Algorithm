#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 801
#define INF 987654321
using namespace std;

int n, e, v1, v2, v1_length = 0, v2_length = 0, answer;
vector<pair<int, int> > vertex[MAX];
int dist[MAX];

void input() {
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		vertex[a].push_back({ b, c });
		vertex[b].push_back({ a, c });
	}

	cin >> v1 >> v2;
}

void initialize() {
	for (int i = 1; i <= MAX; i++) {
		dist[i] = INF;
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
	//1 -> v1 -> v2 -> n
	initialize();
	dijkstra(1);
	v1_length += dist[v1];
	
	initialize();
	dijkstra(v1);
	v1_length += dist[v2];
	
	initialize();
	dijkstra(v2);
	v1_length += dist[n];

	//1 -> v2 -> v1 -> n
	initialize();
	dijkstra(1);
	v2_length += dist[v2];

	initialize();
	dijkstra(v2);
	v2_length += dist[v1];

	initialize();
	dijkstra(v1);
	v2_length += dist[n];

	answer = min(v1_length, v2_length);

	if (answer >= INF || answer < 0) {
		cout << -1;
		return;
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}