#include <iostream>
#include <algorithm>
using namespace std;

long long cache[90];

long long fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	if (cache[n] != 0)
		return cache[n];

	return cache[n] = fib(n - 1) + fib(n - 2);
}

int main() {
	int n;
	cin >> n;

	fill(cache, cache + 90, 0);

	cout << fib(n);

	return 0;
}