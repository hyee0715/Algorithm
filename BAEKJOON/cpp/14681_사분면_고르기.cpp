#include <iostream>
using namespace std;

int x, y;

void input() {
	cin >> x >> y;
}

void solution() {
	if (x > 0 && y > 0) {
		cout << 1;
	}
	else if (x < 0 && y > 0) {
		cout << 2;
	}
	else if (x < 0 && y < 0) {
		cout << 3;
	}
	else {
		cout << 4;
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