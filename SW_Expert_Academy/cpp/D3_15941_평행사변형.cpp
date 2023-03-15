#include <iostream>
using namespace std;

int n;

void input() {
	cin >> n;
}

void solution() {
	cout << n * n << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();
		
		cout << "#" << i + 1 << " ";
		solution();
	}

	return 0;
}