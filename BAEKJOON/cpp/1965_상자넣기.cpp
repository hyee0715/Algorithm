#include <iostream>
#include <algorithm>

#define MAX 1010
using namespace std;

int n;
int box[MAX];
int dp[MAX];

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> box[i];
	}
}

// LIS 이용
void solution() {
	int answer = 0;

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) { // i 위치보다 앞에 있는 j값들 중 가장 긴 부분 수열의 길이 값 + 1이 i 번째 값이 가지는 LIS 값이다.
			if (box[i] > box[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}

		answer = max(dp[i], answer);
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