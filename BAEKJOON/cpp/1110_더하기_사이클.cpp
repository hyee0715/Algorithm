#include <iostream>
using namespace std;

int n, sum, cnt = 0, right_num;

void input() {
	cin >> n;
}

void solution() {
	if (n == 0) {
		cout << 1;
		return;
	}

	int copy = n;

	while (copy != sum) {
		sum = 0;
		right_num = -1;

		while (n > 0) {
			sum += n % 10;

			if (right_num == -1) 
				right_num = n % 10;

			n = n / 10;
		}

		cnt++;

		if (sum >= 10)
			sum = sum % 10;

		n = right_num * 10 + sum;
		sum = n;
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