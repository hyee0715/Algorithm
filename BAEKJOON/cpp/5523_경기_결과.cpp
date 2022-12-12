#include <iostream>
using namespace std;

int n, a, b, a_cnt = 0, b_cnt = 0;

void solution() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		if (a > b) {
			a_cnt++;
			continue;
		}

		if (a < b) {
			b_cnt++;
		}
	}

	cout << a_cnt << " " << b_cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}