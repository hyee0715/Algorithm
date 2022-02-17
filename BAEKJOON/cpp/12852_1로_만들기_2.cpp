#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1000001
using namespace std;

int n;
int dp[MAX];
int answer1;
vector<int> answer2;

void input() {
	cin >> n;
}

void solution() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0 && i % 3 == 0)
			dp[i] = min(min(dp[i - 1] + 1, dp[i / 2] + 1), dp[i / 3] + 1);
		else if (i % 2 == 0 && i % 3 != 0)
			dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
		else if (i % 2 != 0 && i % 3 == 0)
			dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);
		else
      		dp[i] = dp[i - 1] + 1;
	}

	answer1 = dp[n];
	answer2.push_back(n);

	while (1) {
		if (n == 1) {
			break;
		}

		int result1 = MAX, result2 = MAX, result3 = MAX;
		result1 = dp[n - 1] + 1;
		
		if (n % 2 == 0)
			result2 = dp[n / 2] + 1;

		if (n % 3 == 0)
			result3 = dp[n / 3] + 1;

		if (result1 == min(min(result1, result2), result3)) {
			answer2.push_back(n - 1);
			n = n - 1;
		}
		else if (result2 == min(min(result1, result2), result3)) {
			answer2.push_back(n / 2);
			n = n / 2;
		}
		else if (result3 == min(min(result1, result2), result3)) {
			answer2.push_back(n / 3);
			n = n / 3;
		}
	}

	// print answers
	cout << answer1 << "\n";
	
	for (int i = 0; i < answer2.size(); i++) {
		cout << answer2[i] << " ";
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