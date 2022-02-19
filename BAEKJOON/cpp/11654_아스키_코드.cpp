#include <iostream>
using namespace std;

char c;

void input() {
	cin >> c;
}

void solution() {
	cout << (int)c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}