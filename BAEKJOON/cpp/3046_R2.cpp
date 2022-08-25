#include <iostream>
using namespace std;

int r1, r2, s;

void input() {
	cin >> r1 >> s;
}

void solution() {
	r2 = 2 * s - r1;

	cout << r2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}