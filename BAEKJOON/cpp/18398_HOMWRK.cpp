#include <iostream>
using namespace std;

int n, a, b;

void solution() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		cout << a + b << " " << a * b << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		solution();
	}

	return 0;
}