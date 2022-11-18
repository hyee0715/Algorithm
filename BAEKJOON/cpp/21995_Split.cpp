#include <iostream>
#include <string>
using namespace std;

string s, a, b;

void input() {
	cin >> s;
}

void solution() {
	for (int i = 0; i < s.size() / 2; i++) {
		a += s[i];
	}

	for (int i = s.size() / 2; i < s.size(); i++) {
		b += s[i];
	}

	cout << a << " " << b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}