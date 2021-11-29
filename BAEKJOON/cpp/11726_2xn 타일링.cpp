#include <iostream>
#include <algorithm>
using namespace std;

int cache[1001];

int dp(int n) {
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;

	if (cache[n] != -1)
		return cache[n];
	else
		return cache[n] = (dp(n - 1) + dp(n - 2)) % 10007;
}

int main() {
	int n;
	cin >> n;

	fill(cache, cache + 1001, -1);

	cout << dp(n);

	return 0;
}
