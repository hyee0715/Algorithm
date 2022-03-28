#include <iostream>
using namespace std;

int a, b;

void input() {
	cin >> a >> b;
}

void solution() {
	cout << a + b << "\n" << a - b << "\n" << a * b << "\n" << a / b << "\n" << a % b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}