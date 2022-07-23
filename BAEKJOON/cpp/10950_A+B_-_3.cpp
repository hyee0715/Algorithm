#include <iostream>
using namespace std;

int a, b;

void solution() {
	cin >> a >> b;
	
	cout << a + b << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		solution();
	}

	return 0;
}