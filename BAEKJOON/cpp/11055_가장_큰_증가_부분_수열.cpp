#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, sum = 0;
vector<int> v;

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
}

void solution() {
	vector<int> dp(v.size(), 0);

	for (int i = 0; i < n; i++) {
		dp[i] = v[i];

		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				dp[i] = max(dp[i], dp[j] + v[i]) ;
			}
		}

		sum = max(sum, dp[i]);
	}

	cout << sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}