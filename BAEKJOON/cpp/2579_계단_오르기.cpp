#include <iostream>
#include <algorithm>

#define MAX 301
using namespace std;

int n;
int arr[MAX], dp[MAX];

void input() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

//dp[a] = b -> a번째 계단까지 왔을 때, a번재 계단을 밟았을 경우 얻을 수 있는 총 점수의 최댓값은 b이다.
void solution() {
	dp[0] = 0;
	dp[1] = arr[1];
	
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	cout << dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}