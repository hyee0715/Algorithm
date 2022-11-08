#include <iostream>
using namespace std;

int n;
char c;

void input() {
	cin >> n >> c;
}

void solution() {
	for (int i = 0; i < n; i++) {
		cout << c;
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