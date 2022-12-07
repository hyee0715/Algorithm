#include <iostream>
using namespace std;

int limit, speed;

void input() {
	cin >> limit >> speed;
}

void solution() {
	if (speed <= limit) {
		cout << "Congratulations, you are within the speed limit!";
		return;
	}

	if (speed - limit >= 1 && speed - limit <= 20) {
		cout << "You are speeding and your fine is $100.";
		return;
	}

	if (speed - limit >= 21 && speed - limit <= 30) {
		cout << "You are speeding and your fine is $270.";
		return;
	}

	cout << "You are speeding and your fine is $500.";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}