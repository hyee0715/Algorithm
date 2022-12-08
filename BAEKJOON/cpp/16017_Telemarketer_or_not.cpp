#include <iostream>
using namespace std;

int number[4];

void input() {
	for (int i = 0; i < 4; i++) {
		cin >> number[i];
	}
}

void solution() {
	if (number[0] != 8 && number[0] != 9) {
		cout << "answer";
		return;
	}

	if (number[3] != 8 && number[3] != 9) {
		cout << "answer";
		return;
	}

	if (number[1] != number[2]) {
		cout << "answer";
		return;
	}

	cout << "ignore";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}