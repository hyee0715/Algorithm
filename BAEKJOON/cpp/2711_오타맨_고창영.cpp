#include <iostream>
#include <string>
using namespace std;

int n;
string s;

void input() {
	cin >> n >> s;
}

void solution() {
	s.erase(s.begin() + (n - 1));
	//s.erase((n - 1), 1);

	cout << s << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}