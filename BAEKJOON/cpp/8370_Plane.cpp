#include <iostream>
using namespace std;

int sum = 0, a, b;

void solution() {
	for (int i = 0; i < 2; i++) {
		cin >> a >> b;

		sum += a * b;
	}

	cout << sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}