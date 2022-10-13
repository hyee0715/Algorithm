#include <iostream>
using namespace std;

int n, m;

void input() {
	cin >> n >> m;
}

void solution() {
	if (m == 1 || m == 2) {
		cout << "NEWBIE!";
	}
	else if (m <= n) {
		cout << "OLDBIE!";
	}
	else {
		cout << "TLE!";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}