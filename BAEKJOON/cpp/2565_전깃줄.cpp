#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer = -1;
vector<pair<int, int> > v;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
}

void solution() {
	sort(v.begin(), v.end());

	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++) {
		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			if (v[j].second < v[i].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		if (answer < dp[i])
			answer = dp[i];
	}

	cout << n - answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}