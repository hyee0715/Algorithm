#include <iostream>
#include <string>
//#include <algorithm>
using namespace std;

string s;

void input() {
	cin >> s;
}

void solution() {
	for (int i = 0; i < s.size(); i++) {
		s[i] = toupper(s[i]);
	}

	cout << s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}