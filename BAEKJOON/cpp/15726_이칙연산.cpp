#include <iostream>
using namespace std;

long long a, b, c;

void input() {
	cin >> a >> b >> c;
}

void solution() {
	long long result1 = (double)(a * b) / c;
	long long result2 = ((double)a / b) * c;

	if (result1 > result2) {
		cout << result1;
	} else {
		cout << result2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}