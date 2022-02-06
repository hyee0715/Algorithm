#include <iostream>
#include <vector>
using namespace std;

int num[10];
int maxNum = 0;
int maxIdx = 0;

void input() {
	for (int i = 1; i < 10; i++) {
		cin >> num[i];
	}
}

void solution() {
	for (int i = 1; i <= 10; i++) {
		if (num[i] > maxNum) {
			maxNum = num[i];
			maxIdx = i;
		}
	}

	cout << maxNum << "\n" << maxIdx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}
