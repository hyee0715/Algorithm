#include <iostream>
using namespace std;

void solution() {
	int n;
	int sum = 0;

	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum += a;
	}

	cout << sum << "\n";
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