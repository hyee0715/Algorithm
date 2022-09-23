#include <iostream>
#include <string>
using namespace std;

string s;

void input() {
	getline(cin, s);
}

void solution() {
	int count = 0;

	if (s.empty()) {
		cout << 0;
		return;
	}

	count = 1;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ')
			count++;
	}

	if (s[0] == ' ')
		count--;

	if (s[s.size() - 1] == ' ')
		count--;

	cout << count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}