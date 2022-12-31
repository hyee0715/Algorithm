#include <iostream>
using namespace std;

int n;

void solution() {
	cin >> n;

	int max = -1000001;
	int min = 1000001;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;

		if (max < a) {
			max = a;
		}

		if (min > a) {
			min = a;
		}
	}

	cout << min << " " << max << "\n";
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