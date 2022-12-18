#include <iostream>
using namespace std;

int sum;

void input() {
	cin >> sum;
}

void solution() {
	int price;

	for (int i = 0; i < 9; i++) {
		cin >> price;
		sum -= price;
	}

	cout << sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}