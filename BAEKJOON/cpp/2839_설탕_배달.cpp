#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int n, n_copy, cnt;
int answer = INF;

void input() {
	cin >> n;
}

void solution() {
	if (n % 3 == 0) {
		answer = n / 3;
	}

	for (int i = 1; ; i++) {
		cnt = 0;

		if (5 * i > n)
			break;

		n_copy = n - (5 * i);
		cnt += i;

		if (n_copy % 3 != 0)
			continue;
		else {
			cnt += (n_copy / 3);
			answer = min(answer, cnt);
		}
	}

	if (answer == INF)
		cout << "-1";
	else
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