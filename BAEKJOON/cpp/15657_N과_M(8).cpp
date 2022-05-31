#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 8
using namespace std;

int n, m;
int arr[MAX];
bool visit[MAX];
vector<int> v;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void dfs(int idx, int cnt) { // 중복 조합
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = idx; i < n; i++) {
		//if (visit[i] == true) continue;
		visit[i] = true;
		v.push_back(arr[i]);
		dfs(i, cnt + 1);
		visit[i] = false;
		v.pop_back();
	}
}

void solution() {
	sort(arr, arr + n);

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