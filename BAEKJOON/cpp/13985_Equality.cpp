#include <iostream>
#include <string>
using namespace std;

string s;

void input() {
	getline(cin, s);
}

void solution() {
	int a, b, c;
	string t;

	a = s[0] - '0';
	b = s[4] - '0';
	
	for (int i = 8; i < s.size(); i++) {
		t += s[i];
	}

	c = stoi(t);

	if (c == a + b) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}