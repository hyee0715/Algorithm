#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string a, b;
int alphabet[26];

void input() {
	cin >> a >> b;
}

bool check() {
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] != 0)
			return false;
	}

	return true;
}

void solution() {
	for (int i = 0; i < a.size(); i++) {
		alphabet[a[i] - 'a']++;
	}

	for (int i = 0; i < b.size(); i++) {
		alphabet[b[i] - 'a']--;
	}

	if (check()) {
		cout << a << " & " << b << " are anagrams.\n";
	}
	else {
		cout << a << " & " << b << " are NOT anagrams.\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		memset(alphabet, 0, sizeof(alphabet));
		input();
		solution();
	}
	return 0;
}