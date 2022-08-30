#include <iostream>
using namespace std;

int time = 0;

void input() {
	int n;

	for (int i = 0; i < 4; i++) {
		cin >> n;

		time += n;
	}
}

void solution() {
	cout << time / 60 << "\n" << time % 60;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}