#include <iostream>
using namespace std;

int l;

void input() {
	cin >> l;
}

void solution() {
	if (l < 5) {
		cout << 1;
		return;
	}

	int t = (l / 5);

	if (l % 5 != 0) {
		t++;
	}

	cout << t;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}