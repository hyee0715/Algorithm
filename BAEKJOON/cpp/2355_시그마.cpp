#include <iostream>
using namespace std;

long long a, b;

void input() {
	cin >> a >> b;
}

void solution() {
	if (a <= b) {
		cout << (b - a + 1) * (b + a) / 2;
	}
	else { // a > b
		cout << (a - b + 1) * (b + a) / 2;
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