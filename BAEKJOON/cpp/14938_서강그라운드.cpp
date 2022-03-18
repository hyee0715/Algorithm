#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 101
#define INF 987654321
using namespace std;

int n, m, r, item_cnt, answer = 0;
vector<pair<int, int> > vertex[MAX];
int dist[MAX];
int item[MAX];

void input() {
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		int a; 
		cin >> a;

		item[i] = a;
	}

	for (int i = 0; i < r; i++) {
		int b, c, d;
		cin >> b >> c >> d;

		vertex[b].push_back(make_pair(c, d));
		vertex[c].push_back(make_pair(b, d));
	}
}

void initialize() {
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	item_cnt = 0;
}

void dijkstra(int start) {
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

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
		initialize();

		dijkstra(i);

		for (int j = 1; j <= n; j++) {
			if (dist[j] <= m) {
				item_cnt += item[j];
			}
		}

		answer = max(answer, item_cnt);
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