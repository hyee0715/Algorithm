#include <iostream>
#include <string>
using namespace std;

string s;
int c, v;

void input() {
	getline(cin, s);
}

void solution() {
	c = 0, v = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U' && s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != ' ') {
			c++;
		}
		else {
			if (s[i] != ' ')
				v++;
		}
	}

	cout << c << " " << v << "\n";
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