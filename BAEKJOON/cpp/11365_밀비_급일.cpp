#include <iostream>
#include <string>
using namespace std;

string s;

void solution() {
	for (int i = s.size() - 1; i >= 0; i--) {
		cout << s[i];
	}

	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		getline(cin, s);

		if (s == "END")
			break;

		solution();
	}

	return 0;
}