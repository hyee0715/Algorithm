#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<int> alphabet;
int answer;

void initialize() {
	alphabet.assign(26, 0);
	answer = 0;
}

void input() {
	cin >> s;
}

void solution() {
	for (int i = 0; i < s.size(); i++) {
		alphabet[s[i] - 'A']++;
	}

	for (int i = 0; i < alphabet.size(); i++) {
		if (alphabet[i] == 0) {
			answer += (i + 65);
		}
	}

	cout << answer << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		initialize();
		input();
		solution();
	}

	return 0;
}