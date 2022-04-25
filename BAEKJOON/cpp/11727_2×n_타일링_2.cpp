#include <iostream>

#define MAX 1001
using namespace std;

int n;
int dp[MAX];

void input() {
	cin >> n;
}

//dp[a] = b -> 2 * a 크기의 직사각형을 채우는 방법의 수는 b개이다.
void solution() {
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
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