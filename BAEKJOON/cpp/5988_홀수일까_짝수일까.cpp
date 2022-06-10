#include <iostream>
#include <string>
using namespace std;

int n;
string s;

void solution() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		if ((s[s.size() - 1] - '0') % 2 == 0)
			cout << "even\n";
		else
			cout << "odd\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}