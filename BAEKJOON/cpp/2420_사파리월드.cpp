#include <iostream>
#include <cmath>
using namespace std;

long long n, m;

void input() {
	cin >> n >> m;
}

void solution() {
	cout << abs(n - m);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}