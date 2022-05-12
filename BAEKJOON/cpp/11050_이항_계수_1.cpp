#include <iostream>
using namespace std;

int n, k, ans = 0;
bool visit[10];

void input() {
	cin >> n >> k;
}

void dfs(int idx, int cnt) {
	if (cnt == k) {
		ans++;
	}
	else {
		for (int i = idx; i < n; i++) {
			if (visit[idx] == true) continue;
			visit[idx] = true;
			dfs(i, cnt + 1);
			visit[idx] = false;
		}
	}
}

void solution() {
	dfs(0, 0);

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}