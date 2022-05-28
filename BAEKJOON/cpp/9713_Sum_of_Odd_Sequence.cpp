#include <iostream>
using namespace std;

int t, n, sum;

void solution() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		sum = 0;
		for (int j = 0; j <= n; j++) {
			if (j % 2 == 1)
				sum += j;
		}
	
		cout << sum << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}