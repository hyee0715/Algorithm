#include <iostream>
#include <string>
using namespace std;

int n;
string s;

void input() {
	cin >> s;
}

void solution() {
	int cnt = 0;

	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == '(' && s[i + 1] == ')') {
			cnt++;
			continue;
		}

		if (s[i] == '(' && s[i + 1] != ')') {
			cnt++;
			continue;
		}

		if (s[i] != ')' && s[i + 1] == ')') {
			cnt++;
		}
	}

	cout << cnt << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();

		cout << "#" << i + 1 << " ";
		solution();
	}

	return 0;
}