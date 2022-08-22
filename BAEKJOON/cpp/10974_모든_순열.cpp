#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<int> v;
bool visit[9];

void input() {
	cin >> n;
}

void dfs(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			v.push_back(i);
			dfs(cnt + 1);
			visit[i] = false;
			v.pop_back();
		}
	}
}

void solution() {
	memset(visit, false, sizeof(visit));
	dfs(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}