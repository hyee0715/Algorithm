#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;

void input() {
	cin >> s;
}

bool checkJava(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (isupper(s[i])) {
			return true;
		}
	}

	return false;
}

bool checkCpp(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '_') {
			return true;
		}
	}

	return false;
}

bool errorCheck(string s) {
	bool isJava = checkJava(s);
	bool isCpp = checkCpp(s);

	if (isJava && isCpp) {
		return false;
	}

	if ((s[0] == '_') || isupper(s[0])) {
		return false;
	}

	if (s[s.length() - 1] == '_') {
		return false;
	}

	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == s[i + 1] && s[i] == '_') {
			return false;
		}
	}

	return true;
}

string makeCpp(string s) {
	string ret;

	for (int i = 0; i < s.length(); i++) {
		if (isupper(s[i])) {
			ret += "_";
			ret += tolower(s[i]);
		}
		else {
			ret += s[i];
		}
	}

	return ret;
}

string makeJava(string s) {
	string ret;

	bool up = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '_') {
			up = true;
		}
		else {
			if (up) {
				ret += toupper(s[i]);
				up = false;
			}
			else {
				ret += s[i];
			}
		}
	}

	return ret;
}

void solution() {
	if (!errorCheck(s)) {
		cout << "Error!";
		return;
	}

	if (checkJava(s)) {
		cout << makeCpp(s);
		return;
	}

	cout << makeJava(s);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}