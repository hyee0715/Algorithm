#include <iostream>
#include <queue>

#define MAX 100000
using namespace std;

int n, k, time = 0;
int d[] = { -1, 1};
int visit[MAX];

void solution() {
	queue<pair<int, int> > q; // 현재위치, 경과 시간
	q.push(make_pair(n, time));
	visit[n] = true;

	while (!q.empty()) {
		int now = q.front().first;
		int time = q.front().second;
		q.pop();

		if (now == k) {
			cout << time << endl;
			return;
		}

		for (int i = 0; i < 2; i++) {
			int go = now + d[i];

			if (go >= 0 && go < MAX) {
				if (visit[go] == false) {
					q.push(make_pair(go, time + 1));
					visit[go] = true;
				}
			}
		}
		
		if (now * 2 < MAX) {
			if (visit[now * 2] == false) {
				q.push(make_pair(now * 2, time + 1));
				visit[now * 2] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	solution();

	return 0;
}