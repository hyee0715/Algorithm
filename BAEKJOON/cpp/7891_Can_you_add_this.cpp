#include <iostream>
using namespace std;

long long x, y;

void input() {
	cin >> x >> y;
}

void solution() {
	cout << x + y << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}