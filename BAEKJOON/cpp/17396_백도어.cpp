#include <iostream>
#include <queue>
#include <vector>

#define MAX 100001
#define INF 1e11
using namespace std;

int n, m;
int eyesight[MAX];
vector<pair<int, long long> > vertex[MAX];
long long dist[MAX];

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> eyesight[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (eyesight[a] == 1 || eyesight[b] == 1) { //상대 시야가 보이는 분기점이면 입력에 넣지 않는다.
			if ((a != n - 1) && b != n - 1) {
				continue;
			}
		}

		vertex[a].push_back({ b, c });
		vertex[b].push_back({ a, c });
	}
}

void dijkstra(int start) {
	priority_queue<pair<long long, int> > pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (int i = 0; i < vertex[cur].size(); i++) {
			 int next = vertex[cur][i].first;
			 long long n_cost = vertex[cur][i].second;

			if (dist[next] > cost + n_cost) {
				dist[next] = cost + n_cost;
				pq.push({ -dist[next], next });
;			}
		}
	}
}

void solution() {
	for (int i= 0; i < n; i++) {
		dist[i] = INF;
	}

	dijkstra(0);

	if (dist[n - 1] != INF)
		cout << dist[n - 1];
	else
		cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}