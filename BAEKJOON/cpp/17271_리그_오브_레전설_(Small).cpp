#include <iostream>

#define MAX 10001
using namespace std;

int n, m;
long long dp[MAX][101];

void input() {
	cin >> n >> m;
}

//dp[n][m] = c -> n���� �ð����� �ο�µ� A ��ų �ð��� 1���̰� B ��ų �ð��� m���� ��, 
//������ ��ų ������ C���̴�.
void solution() {
	//dp[1][2~100]�� ��� 1�� �ʱ�ȭ
	for (int i = 2; i <= 100; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (i > j) {
				dp[i][j] = (dp[i - 1][j] + dp[i - j][j]) % 1000000007;
			}
			else if (i == j) {
				dp[i][j] = 2;
			}
			else { // i < j
				dp[i][j] = 1;
			}
		}
	}

	cout << dp[n][m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}