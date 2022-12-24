#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;

void input() {
	getline(cin, s);
}

void solution() {
	vector<int> alphabet(26, 0);

	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}

	for (int i = 0; i < s.length(); i++) {
		if (s[i] < 'a' || s[i] > 'z') {
			continue;
		}

		alphabet[s[i] - 'a']++;
	}

	string pangram = "pangram";
	string missing = "missing ";
	bool isMissing = false;

	for (int i = 0; i < alphabet.size(); i++) {
		if (alphabet[i] == 0) {
			isMissing = true;

			missing += (i + 'a');
		}
	}

	if (isMissing) {
		cout << missing << "\n";
		return;
	}

	cout << pangram << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	cin.ignore();

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}