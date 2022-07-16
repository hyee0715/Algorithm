#include <iostream>
#include <string>
using namespace std;

string s;

void input() {
	cin >> s;
}

void solution() {
	for (int i = 0; i < 3; i++) {
		if (s[i] != '5') {
			cout << "NO";
			return;
		}
	}

	cout << "YES";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}