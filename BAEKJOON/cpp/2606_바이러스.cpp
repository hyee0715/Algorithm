#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 101
using namespace std;

int n, e, cnt = 0;
vector<int> v[MAX];
bool visit[MAX];

void input() {
	cin >> n;
	cin >> e;
	
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void bfs(int a) {
	queue<int> q;
	q.push(a);
	visit[a] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];

			if (visit[nx] == false) {
				q.push(nx);
				visit[nx] = true;
				cnt++;
			}
		}
	}
}

//void dfs(int x) {
//	if (visit[x]) return;
//
//	cnt++;
//	visit[x] = true;
//
//	for (int i = 0; i < v[x].size(); i++) {
//		int nx = v[x][i];
//		
//		dfs(nx);
//	}
//}

void solution() {
	memset(visit, false, sizeof(visit));

	bfs(1);
	cout << cnt;

	/*dfs(1);
	cout << cnt - 1;*/
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}