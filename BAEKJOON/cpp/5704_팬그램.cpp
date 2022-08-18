#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> alphabet;
string s;

bool check() {
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == 0)
			return false;
	}

	return true;
}

void solution() {
	alphabet.assign(26, 0);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') continue;

		alphabet[s[i] - 'a']++;
	}

	if (check())
		cout << "Y\n";
	else
		cout << "N\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		getline(cin, s);

		if (s == "*")
			break;

		solution();
	}

	return 0;
}