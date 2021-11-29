#include <iostream>
using namespace std;

void dfs(int k, int n, int m, int arr[], bool visited[]) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[k] = i;
				dfs(k + 1, n, m, arr, visited);
				visited[i] = false;
			}
		}
	}
}

int main() {
	int n, m;
	int arr[9] = { 0, };
	bool visited[9] = { 0, };

	cin >> n >> m;

	dfs(0, n, m, arr, visited);
}