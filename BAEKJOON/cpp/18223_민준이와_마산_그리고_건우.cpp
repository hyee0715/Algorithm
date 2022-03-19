#include <iostream>
#include <vector>
#include <queue>

#define MAX 5001
#define INF 987654321
using namespace std;

int v, e, p, min_distance;
vector<pair<int, int> > vertex[MAX];
int dist[MAX];

void input() {
	cin >> v >> e >> p;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		vertex[a].push_back(make_pair(b, c));
		vertex[b].push_back(make_pair(a, c));
	}
}

void initialize() {
	for (int i = 1; i <= MAX; i++) {
		dist[i] = INF;
	}
}

void dijkstra(int start) {
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;

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
	initialize();

	// 출발지에서 도착지까지의 그냥 최단경로 구하기
	dijkstra(1);

	min_distance = dist[v];

	// 건우를 구하고 가는 최단경로 구하기
	// 출발지에서 건우가 있는 곳까지의 거리
	int gun = dist[p];

	// 건우가 있는 곳에서 도착지까지의 거리
	initialize();
	dijkstra(p);

	gun += dist[v];

	if (gun == min_distance)
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}