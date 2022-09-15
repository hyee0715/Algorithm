#include <iostream>
using namespace std;

long long a, b, c;

void input() {
	cin >> a >> b >> c;
}

void solution() {
	cout << a + b + c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}