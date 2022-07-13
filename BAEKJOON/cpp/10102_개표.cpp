#include <iostream>

using namespace std;

int n, a = 0, b = 0;
char c;

void input() {
	cin >> n;
}

void solution() {
	for (int i = 0; i < n; i++) {
		cin >> c;

		if (c == 'A')
			a++;
		else
			b++;
	}

	if (a > b)
		cout << "A";
	else if (a == b)
		cout << "Tie";
	else
		cout << "B";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}