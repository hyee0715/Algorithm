#include <iostream>
#include <string>
using namespace std;

string s;
int idx = 0;

void input() {
	cin >> s;
}

void solution() {
	while (1) {
		for (int i = 0; i < 10; i++) {
			cout << s[idx++];

			if (idx == s.size())
				break;
		}

		if (idx == s.size())
			break;
		
		cout << "\n";
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