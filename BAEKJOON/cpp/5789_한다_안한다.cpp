#include <iostream>
#include <string>
using namespace std;

string s;

void input() {
	cin >> s;
}

void solution() {
	int mid = (s.length() / 2) - 1;

	if (s[mid] == s[mid + 1]) {
		cout << "Do-it\n";
		return;
	}

	cout << "Do-it-Not\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}