#include <iostream>
using namespace std;

int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		cin >> a >> b;
		
		cout << "Case #" << i << ": " << a + b << "\n";
	}

	return 0;
}