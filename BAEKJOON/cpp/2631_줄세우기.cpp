#include <iostream>
#include <algorithm>

#define MAX 201
using namespace std;

int n, max_num = 0;
int arr[MAX], dp[MAX];

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	//LIS
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;

		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		max_num = max(max_num, dp[i]);
	}

	cout << n - max_num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}