#include <iostream>
#include <vector>

#define MAX 7
using namespace std;

int arr[MAX];
int visit[MAX];
int n, m;

void input() {
	cin >> n >> m;
}

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << visit[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		visit[cnt] = arr[i];
		dfs(cnt + 1);
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

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