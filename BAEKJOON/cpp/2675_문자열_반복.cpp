#include <iostream>
#include <string>
using namespace std;

int n;
string s;

void input() {
	cin >> n >> s;
}

void solution() {
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < n; j++) {
			cout << s[i];
		}
	}

	cout << "\n";
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