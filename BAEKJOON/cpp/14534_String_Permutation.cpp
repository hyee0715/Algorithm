#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
vector<char> v;
vector<bool> visit;

void initialize() {
	v.clear();
	visit.assign(5, false);
}

void input() {
	cin >> s;
}

void dfs(int cnt) {
	if (cnt == s.size()) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			v.push_back(s[i]);
			dfs(cnt + 1);
			v.pop_back();
			visit[i] = false;
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

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		initialize();
		input();
		
		cout << "Case # " << i + 1 << ":\n";
		solution();
	}

	return 0;
}