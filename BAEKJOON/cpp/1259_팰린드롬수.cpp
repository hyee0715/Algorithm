#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

void solution() {
	string reverse_s = s;
	reverse(reverse_s.begin(), reverse_s.end());

	if (reverse_s == s)
		cout << "yes\n";
	else
		cout << "no\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> s;

		if (s == "0")
			break;
		
		solution();
	}

	return 0;
}