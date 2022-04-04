#include <iostream>
using namespace std;

int a, b;

void solution() {
	cout << a + b << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> a >> b;

		if (a == 0 && b == 0)
			break;
		
		solution();
	}

	return 0;
}