#include <iostream>
#include <cmath>
using namespace std;

long long a, b;

void input() {
	cin >> a >> b;
}

void solution() {
	if (a < b) {
		cout << (b - a) - 1 << "\n";
		for (long long i = a + 1; i < b; i++) {
			cout << i << " ";
		}
	}
	else {
		cout << (a - b) - 1 << "\n";
		for (long long i = b + 1; i < a; i++) {
			cout << i << " ";
		}
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