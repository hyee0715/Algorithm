#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cnt;
string s;
vector<int> alphabet;

void solution() {
	alphabet.clear();
	alphabet.assign(26, 0);
	cnt = 0;

	for (int i = 0; i < s.size(); i++) {
		s[i] = tolower(s[i]);
		
		if (s[i] >= 'a' && s[i] <= 'z') {
			alphabet[s[i] - 'a']++;
		}
	}
	
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > 0) {
			cnt++;
		}
	}

	cout << cnt << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin.ignore();

	while (1) {
		getline(cin, s);

		if (s == "#")
			break;

		solution();
	}

	return 0;
}