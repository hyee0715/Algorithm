#include <iostream>
using namespace std;

int n, answer = 0;

void solution() {
	cin >> n;

	int a;
	for (int i = 0; i < 5; i++) {
		cin >> a;

		if (a == n)
			answer++;
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