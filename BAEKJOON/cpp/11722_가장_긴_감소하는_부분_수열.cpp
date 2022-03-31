#include <iostream>
#include <algorithm>

#define MAX 1001
using namespace std;

int n;
int arr[MAX], dp[MAX];

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	int answer = 0;

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;

		for (int j = 1; j < i; j++) {
			if (arr[i] < arr[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}

		answer = max(answer, dp[i]);
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