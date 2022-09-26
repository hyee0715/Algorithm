#include <iostream>
using namespace std;

int n, m;

void solution() {
	if (m % n != 0) {
		cout << m << " is NOT a multiple of " << n << ".\n";
	}
	else {
		cout << m << " is a multiple of " << n << ".\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	while (1) {
		cin >> m;

		if (m == 0) break;

		solution();
	}

	return 0;
}