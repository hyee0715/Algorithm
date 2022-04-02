#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
set<string> s;
vector<string> v;

void solution() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		s.insert(str);
	}

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;

		if (s.find(str) != s.end()) {
			v.push_back(str);
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << "\n";

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}