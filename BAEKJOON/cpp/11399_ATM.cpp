#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 1010
using namespace std;

int n;
vector<int> vec;
int dp[MAX];
int sum = 0;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
}

void solution() {
	sort(vec.begin(), vec.end());

	dp[0] = vec[0];

	for (int i = 1; i < vec.size(); i++) {
		dp[i] = dp[i - 1] + vec[i];
	}

	for (int i = 0; i < vec.size(); i++) {
		sum += dp[i];
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