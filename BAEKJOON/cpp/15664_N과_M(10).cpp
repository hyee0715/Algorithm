#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

#define MAX 8
using namespace std;

int n, m;
int arr[MAX];
bool visit[MAX];
vector<int> v;
set<string> duplication; // 중복 방지

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

bool isDuplicate() { // 중복이 있으면 true 리턴, 중복이 없으면 false 리턴
	string temp = "";

	for (int i = 0; i < v.size(); i++) {
		char a = v[i] + '0';
		temp = temp + a;
	}

	if (duplication.find(temp) == duplication.end()) {
		duplication.insert(temp);
		return false;
	}
	else {
		return true;
	}
}

void dfs(int idx, int cnt) { // 조합
	if (cnt == m) {
		if (!isDuplicate()) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << "\n";
		}

		return;
	}

	for (int i = idx; i < n; i++) {
		if (visit[i] == true) continue;
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