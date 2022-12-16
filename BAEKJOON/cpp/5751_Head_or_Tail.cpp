#include <iostream>
using namespace std;

int n;

void solution() {
	int winner;
	int mary = 0, john = 0;

	for (int i = 0; i < n; i++) {
		cin >> winner;

		if (winner == 0) {
			mary++;
			continue;
		}

		john++;
	}

	cout << "Mary won " << mary << " times and John won " << john << " times\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> n;
	
		if (n == 0) {
			break;
		}

		solution();
	}

	return 0;
}