#include <iostream>
#include <string>
using namespace std;

string s;
string cam = "CAMBRIDGE";

void input() {
	cin >> s;
}

void solution() {
	for (int i = 0; i < cam.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (cam[i] == s[j]) {
				s[j] = '0';
			}
		}
	}

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') continue;
		cout << s[i];
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