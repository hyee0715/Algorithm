#include <iostream>
using namespace std;

int a, b;

void input() {
	cin >> a >> b;
}

void solution() {
	if (a + b == 1) {
		cout << 2 << "\n";
		return;
	}

	cout << 1 << "\n";
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