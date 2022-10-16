#include <iostream>
using namespace std;

int a, b;

void input() {
	cin >> a >> b;
}

void solution() {
	cout << a + b << "\n";
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