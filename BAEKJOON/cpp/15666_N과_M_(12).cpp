#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

#define MAX 8
using namespace std;

int n, m;
int arr[MAX];
int visit[MAX];
set<string> s;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

//중복 조합
void dfs(int idx, int cnt) {
	if (cnt == m) {
		string str;

		for (int i = 0; i < m; i++) {
			str += visit[i] + '0';
		}

		if (s.find(str) == s.end()) {
			s.insert(str);

			for (int i = 0; i < m; i++) {
				cout << visit[i] << " ";
			}
			cout << "\n";
		}
	}
	else {
		for (int i = idx; i < n; i++) {
			visit[cnt] = arr[i];
			dfs(i, cnt + 1);
		}
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