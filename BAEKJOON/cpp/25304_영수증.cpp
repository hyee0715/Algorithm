#include <iostream>
using namespace std;

int x, n, a, b, sum = 0;

void solution() {
	cin >> x >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		sum += (a * b);
	}

	if (sum == x)
		cout << "Yes";
	else
		cout << "No";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}