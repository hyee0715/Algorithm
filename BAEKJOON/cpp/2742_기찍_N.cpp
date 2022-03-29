#include <iostream>
using namespace std;

int n;

void input() {
	cin >> n;
}

void solution() {
	for (int i = n; i >= 1; i--) {
		cout << i << "\n";
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