#include <iostream>
using namespace std;

int a, b, c;

void solution() {
	if (a > b && a > c) {
		if (a * a == (b * b + c * c))
			cout << "right\n";
		else
			cout << "wrong\n";
	}
	else if (b > a && b > c) {
		if (b * b == (a * a + c * c))
			cout << "right\n";
		else
			cout << "wrong\n";
	}
	else if (c > a && c > b) {
		if (c * c == (a * a + b * b))
			cout << "right\n";
		else
			cout << "wrong\n";
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