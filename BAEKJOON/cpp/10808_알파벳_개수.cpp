#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s;
int alphabet[26];

void input() {
	cin >> s;
}

void solution() {
	memset(alphabet, 0, sizeof(alphabet));

	for (int i = 0; i < s.size(); i++) {
		alphabet[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
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