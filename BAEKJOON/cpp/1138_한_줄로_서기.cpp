#include <iostream>
#include <vector>

#define MAX 11
using namespace std;

int n, arr[MAX];
bool visit[MAX];
vector<int> v;

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

bool check() {
	for (int i = 0; i < v.size(); i++) {
		int cnt = 0;
		
		for (int j = 0; j < i; j++) {
			if (v[j] > v[i]) {
				cnt++;
			}
		}

		if (cnt != arr[v[i]])
			return false;
	}

	return true;
}

void dfs(int cnt) {
	if (cnt == n) {
		if (check()) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
		}

		return;
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