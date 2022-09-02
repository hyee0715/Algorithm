#include <iostream>
using namespace std;

int a, b, sum;

void input() {
	cin >> a >> b;
}

void solution() {
	sum = a + b;
	
	cout << a << " + " << b << " = " << sum << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int  tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		input();

		cout << "Case #" << i << ": ";
		solution();
	}
	
	return 0;
}