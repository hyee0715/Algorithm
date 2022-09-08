#include <iostream>
using namespace std;

int s, m, l;

void input() {
	cin >> s >> m >> l;
}

void solution() {
	int sum = 1 * s + 2 * m + 3 * l;

	if (sum >= 10)
		cout << "happy";
	else
		cout << "sad";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}