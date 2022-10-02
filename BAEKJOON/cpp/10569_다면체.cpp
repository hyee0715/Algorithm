#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int v, e;

void input() {
	cin >> v >> e;
}

void solution() {
	int n = 2 - v + e;

	cout << n << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}