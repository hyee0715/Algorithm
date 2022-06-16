#include <iostream>
#include <cmath>
using namespace std;

int n;
long long answer = 0;

void input() {
	cin >> n;
}

void solution() {
	while (n > 0) {
		long long temp = pow(n % 10, 5);
		answer += temp;
		n = n / 10;
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}