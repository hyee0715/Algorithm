#include <iostream>
using namespace std;

int a, b, cnt = 0;

void input() {
	cin >> a >> b;
}

void solution() {
	while (a >= 2 && b >= 1) {
		cnt++;
		a -= 2;
		b -= 1;
	}

	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}