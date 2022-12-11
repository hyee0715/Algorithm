#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;

void input() {
	cin >> s >> t;
}

void check(string s, string t) {
	if (s == t) {
		cout << 1;
		exit(0);
	}

	if (s.size() == t.size()) {
		return;
	}

	if (t[t.size() - 1] == 'A') {
		string temp_t(t);
		check(s, temp_t.erase(temp_t.size() - 1, 1));
	}

	if (t[0] == 'B') {
		string temp_t(t);
		temp_t.erase(0, 1);
		reverse(temp_t.begin(), temp_t.end());

		check(s, temp_t);
	}
}

void solution() {
	check(s, t);

	cout << 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}