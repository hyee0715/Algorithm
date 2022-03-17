#include <iostream>
#include <vector>
#include <cstring>

#define MAX 101
using namespace std;

int n, a, b, m;
vector<int> vec[MAX];
bool visit[MAX];
bool flag = false;

void input() {
	cin >> n >> a >> b >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		vec[x].push_back(y);
		vec[y].push_back(x);
	}
}

void dfs(int x, int cnt) {
	visit[x] = true;

	if (x == b) {
		cout << cnt;
		flag = true;
		return;
	}

	for (int i = 0; i < vec[x].size(); i++) {
		int nx = vec[x][i];

		if (visit[nx] == false) {
			dfs(nx, cnt + 1);
		}
	}

	return;
}

void solution() {
	memset(visit, false, sizeof(visit));

	dfs(a, 0);

	if (!flag)
		cout << "-1";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}