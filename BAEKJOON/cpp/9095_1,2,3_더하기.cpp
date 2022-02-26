#include <iostream>
#include <vector>

#define MAX 12
using namespace std;

int n;
int dp[MAX];
vector<int> answer;

// dp[a] = b -> ���� a�� �־����� ��, a�� 1,2,3�� ������ ��Ÿ���� ����� ���� b���̴�.
void solution() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	answer.push_back(dp[n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> n;

		solution();
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}