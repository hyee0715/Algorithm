#include <iostream>
#include <string>
using namespace std;

int n;

void input() {
	cin >> n;
}

void solution() {
	cin.ignore();

	string s;

	for (int i = 1; i <= n; i++) {
		getline(cin, s);

		cout << i << ". " << s << "\n";
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