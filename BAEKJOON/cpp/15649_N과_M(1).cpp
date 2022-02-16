#include <iostream>
#include <vector>

#define MAX 8
using namespace std;

int arr[MAX];
bool visit[MAX];
vector<int> v;
int n, m;

void input() {
	cin >> n >> m;
}

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		v.push_back(arr[i]);
		dfs(cnt + 1);
		v.pop_back();
		visit[i] = false;
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