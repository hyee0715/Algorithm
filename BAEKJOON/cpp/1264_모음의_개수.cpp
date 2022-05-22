#include <iostream>
#include <string>
using namespace std;

int cnt = 0;
string s;

void solution() {
	cnt = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
			cnt++;
		}
	}

	cout << cnt << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		getline(cin, s);

		if (s == "#")
			break;
	
		solution();
	}

	return 0;
}