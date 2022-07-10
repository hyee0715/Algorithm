#include <iostream>
using namespace std;

int n, m;

void input() {
	cin >> n >> m;
}

void solution() {
	n = n / 2;
	m = m / 2;

	if (n < m)
		cout << n;
	else
		cout << m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}