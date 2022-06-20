#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

void input() {
	cin >> s;
}

void solution() {
	string rev = s;
	reverse(rev.begin(), rev.end());

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != rev[i]) {
			cout << "false";
			return;
		}
	}

	cout << "true";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}