#include <iostream>
using namespace std;

int n[5];
double sum = 0;

void input() {
	for (int i = 0; i < 5; i++) {
		cin >> n[i];
	}
}

void solution() {
	for (int i = 0; i < 5; i++) {
		if (n[i] >= 40) {
			sum += n[i];
		}
		else {
			sum += 40;
		}
	}

	cout << (int)(sum / 5);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}