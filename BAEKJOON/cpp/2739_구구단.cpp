#include <iostream>

using namespace std;

int n;

void input() {
	cin >> n;
}

void solution() {
	for (int i = 1; i <= 9; i++) {
		cout << n << " * " << i << " = " << n * i << "\n";
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