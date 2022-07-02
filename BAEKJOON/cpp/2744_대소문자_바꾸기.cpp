#include <iostream>
#include <string>
using namespace std;

string s;

void input() {
	cin >> s;
}

void solution() {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 65 && s[i] <= 90) { //대문자
			s[i] = tolower(s[i]);
		}
		else { //소문자
			s[i] = toupper(s[i]);
		}
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