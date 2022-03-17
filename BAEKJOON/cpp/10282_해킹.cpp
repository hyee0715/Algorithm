#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 10001
#define INF 987654321
using namespace std;

int n, d, c;
vector<pair<int, int> > vertex[MAX];
int dist[MAX];
pair<int, int> answer; // 총 감염되는 컴퓨터 수, 마지막 컴퓨터가 감염되기까지 걸리는 시간

void initialize() {
	for (int i = 0; i < MAX; i++) {
		vertex[i].clear();
		dist[i] = INF;
		answer = { 0, 0 };
	}
}

void input() {
	cin >> n >> d >> c;

	for (int i = 0; i < d; i++) {
		int a, b, s;
		cin >> a >> b >> s;

		vertex[b].push_back(make_pair(a, s));
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
	dijkstra(c);

	int maxNum = -1;

	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			answer.first++;
			maxNum = max(maxNum, dist[i]);
		}
	}

	answer.second = maxNum;

	cout << answer.first << " " << answer.second << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		initialize();
		input();
		solution();
	}
	
	return 0;
}