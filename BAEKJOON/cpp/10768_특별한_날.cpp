#include <iostream>
using namespace std;

int month, day;

void input() {
	cin >> month >> day;
}

void solution() {
	if (month > 2) {
		cout << "After";
		return;
	}

	if (month == 2) {
		if (day == 18) {
			cout << "Special";
			return;
		}

		if (day > 18) {
			cout << "After";
			return;
		}
	}

	cout << "Before";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}