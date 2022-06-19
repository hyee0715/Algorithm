#include <iostream>
#include <string>

using namespace std;

string s;

void input() {
	cin >> s;
}

void solution() {
	cout << s[0] << s[s.size() - 1] << "\n";
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