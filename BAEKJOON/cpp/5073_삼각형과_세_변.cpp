#include <iostream>
using namespace std;

int a, b, c;

void solution() {
	if (a > b && a > c) {
		if (a >= b + c) {
			cout << "Invalid\n";
			return;
		}
	}
	else if (b > a && b > c) {
		if (b >= a + c) {
			cout << "Invalid\n";
			return;
		}
	}
	else if (c > a && c > b) {
		if (c >= a + b) {
			cout << "Invalid\n";
			return;
		}
	}

	if (a == b && b == c) {
		cout << "Equilateral\n";
	}
	else if ((a == b && b != c) || (b == c && c != a) || (a == c & c != b)) {
		cout << "Isosceles\n";
	}
	else if (a != b != c) {
		cout << "Scalene\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
			break;

		solution();
	}

	return 0;
}