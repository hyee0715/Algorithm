#include <iostream>
#include <cstring>

#define MAX 1001
using namespace std;

double average;
int frequency[MAX];
int mode, modeIdx;

void solution() {
	memset(frequency, 0, sizeof(frequency));

	int input, sum = 0;
	for (int i = 0; i < 10; i++) {
		cin >> input;

		sum += input;
		frequency[input]++;
	}

	//최빈값 구하기
	mode = frequency[0];
	modeIdx = 0;

	for (int i = 1; i < MAX; i++) {
		if (mode < frequency[i]) {
			mode = frequency[i];
			modeIdx = i;
		}
	}

	average = (double)sum / 10;

	cout << (int)average << "\n" << modeIdx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}