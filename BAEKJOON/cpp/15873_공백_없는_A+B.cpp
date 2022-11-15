#include <iostream>
#include <string>
using namespace std;

string s, n1, n2;

void input() {
	cin >> s;
}

void solution() {
	if (s.size() == 4) {
		n1 += s[0];
		n1 += s[1];

		n2 += s[2];
		n2 += s[3];

		cout << stoi(n1) + stoi(n2);
		return;
	}

	if (s.size() == 3) {
		if (s[0] == '1') {
			n1 += s[0];
			n1 += s[1];

			n2 += s[2];

			cout << stoi(n1) + stoi(n2);
			return;
		}

		if (s[0] != '1') {
			n1 += s[0];

			n2 += s[1];
			n2 += s[2];

			cout << stoi(n1) + stoi(n2);
			return;
		}
	}

	n1 += s[0];
	n2 += s[1];

	cout << stoi(n1) + stoi(n2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}