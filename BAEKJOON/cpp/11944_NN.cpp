#include <iostream>
#include <string>
using namespace std;

int n, m;

void input() {
	cin >> n >> m;
}

void solution() {
	string s;
	string str_n = to_string(n);
	
	for (int i = 0; i < n; i++) {
		s += str_n;
	}
	
	if (s.length() > m) {
		s = s.substr(0, m);
	}

	cout << s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}