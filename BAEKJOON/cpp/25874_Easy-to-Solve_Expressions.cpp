#include <iostream>
using namespace std;

int a, b, c;

void input() {
	cin >> a >> b >> c;
}

void solution() {
	if (a + b == c || b + c == a || a + c == b) {
		cout << 1;
		return;
	}

	if (a * b == c || b * c == a || a * c == b) {
		cout << 2;
		return;
	}
	
	cout << 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solution();

	return 0;
}