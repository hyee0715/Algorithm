#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int a, b;

void input() {
	cin >> a >> b;
}

bool is_prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

bool is_palindrome(int n) {
	string s = to_string(n);

	string rev_s = s;
	reverse(rev_s.begin(), rev_s.end());

	if (s == rev_s)
		return true;

	return false;
}

void solution() {
	for (int i = a; i <= 10000000; i++) {
		if (i > b)
			break;

		if (!is_palindrome(i))
			continue;

		if (is_prime(i)) {
			cout << i << "\n";
		}
	}

	cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}