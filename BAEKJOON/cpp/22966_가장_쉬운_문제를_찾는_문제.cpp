#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
vector<pair<int, string> > v;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		int a;

		cin >> s >> a;

		v.push_back({ a, s });
	}
}

void solution() {
	sort(v.begin(), v.end());

	cout << v[0].second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}