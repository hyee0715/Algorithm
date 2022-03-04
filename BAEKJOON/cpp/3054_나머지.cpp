#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int num[10];
int remain[42]; // ³ª¸ÓÁö 0~41
int answer = 0;

void input() {
	for (int i = 0; i < 10; i++) {
		cin >> num[i];
	}
}

void solution() {
	memset(remain, 0, sizeof(remain));

	for (int i = 0; i < 10; i++) {
		int n = num[i] % 42;
		remain[n]++;
	}

	for (int i = 0; i < 42; i++) {
		if (remain[i] != 0)
			answer++;
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}