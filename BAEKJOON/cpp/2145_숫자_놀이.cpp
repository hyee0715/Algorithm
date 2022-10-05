#include <iostream>
using namespace std;

int n;

void solution() {
	int sum = 0;

	while (n >= 10) {
		while (n > 0) {
			sum += (n % 10);
			n = n / 10;
		}

		n = sum;
		sum = 0;
	}

	cout << n << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> n;

		if (n == 0) break;

		solution();
	}

	return 0;
}