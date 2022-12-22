#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

string s;

void input() {
	getline(cin, s);
}

void solution() {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}

	string rev(s);
	reverse(rev.begin(), rev.end());

	if (rev == s) {
		cout << "Yes\n";
		return;
	}

	cout << "No\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	cin.ignore();

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}