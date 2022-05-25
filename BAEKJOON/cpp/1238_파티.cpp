#include <iostream>
#include <queue>
#include <vector>

#define MAX 1001
#define INF 987654321
using namespace std;

int n, m, x, max_time = 0;
vector<pair<int, int> > vertex[MAX];
int dist[MAX], time[MAX];


void input() {
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		vertex[a].push_back({ b, c });
	}
}

void initialize() {
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
}

void dijkstra(int start) {
	priority_queue<pair<int, int > > pq;
	pq.push({ 0, start });
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
				pq.push({ -dist[next], next });
			}
		}
	}
}

void solution() {
	//각각 N명의 학생의 마을에서 X번 마을까지의 시간을 time에 저장
	for (int i = 1; i <= n; i++) {
		initialize();

		dijkstra(i);

		time[i] = dist[x];
	}

	// X번 마을에서 N명의 학생의 마을까지의 시간을 추가로 더한다.
	initialize();
	dijkstra(x);

	for (int i = 1; i <= n; i++) {
		time[i] += dist[i];
	}

	//각 시간중에 최댓값 구한다.
	for (int i = 1; i <= n; i++) {
		if (max_time < time[i]) {
			max_time = time[i];
		}
	}

	cout << max_time;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}