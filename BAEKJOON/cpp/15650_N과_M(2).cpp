#include <iostream>
#include <vector>

#define MAX 8
using namespace std;

int arr[MAX];
bool visit[MAX];
int n, m;

void input() {
	cin >> n >> m;
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < n; i++) {
			if (visit[i] == true) {
				cout << arr[i] << " ";
			}
		}
		cout << "\n";
	}

	for (int i = idx; i < n; i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		dfs(i, cnt + 1);
		visit[i] = false;
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	dfs(0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}