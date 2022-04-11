#include <iostream>
using namespace std;

int n, answer = 0;

void solution() {
	while (1) {
		cin >> n;

		if (n == -1)
			break;

		answer += n;
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}