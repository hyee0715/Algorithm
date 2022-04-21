#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cnt, answer;
string arr[3];

void input() {
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
}

void solution() {
	for (int i = 0; i < 3; i++) {
		cnt = 1;
		answer = 1;

		for (int j = 0; j < 8 - 1; j++) {
			if (arr[i][j] == arr[i][j + 1]) {
				cnt++;
				answer = max(answer, cnt);
			}
			else {
				cnt = 1;
			}
		}

		cout << answer << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}