#include <iostream>
using namespace std;

int r, s;

void input() {
	cin >> r >> s;
}

void solution() {
	int sum = r * 8 + s * 3;

	cout << sum - 28;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}