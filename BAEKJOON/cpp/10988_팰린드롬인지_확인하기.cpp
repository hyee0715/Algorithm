#include <iostream>
#include <string>
using namespace std;

string s;

void input() {
	cin >> s;
}

bool palindrome_check(int left, int right, string s) {
	while (left < right) {
		if (s[left] != s[right])
			return false;

		left++;
		right--;
	}

	return true;
}

void solution() {
	if (palindrome_check(0, s.size() - 1, s))
		cout << 1;
	else
		cout << 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}