#include <iostream>
#include <string>
using namespace std;

string s;

void input() {
	cin >> s;
}

bool check(int left, int right) {
	int l = left + 1;
	int r = right;
	bool is_pseudo_palindrome = true;

	while (l < r) {
		if (s[l] != s[r]) {
			is_pseudo_palindrome = false;
			break;
		}

		l++;
		r--;
	}

	if (is_pseudo_palindrome)
		return true;

	is_pseudo_palindrome = true;

	l = left;
	r = right - 1;

	while (l < r) {
		if (s[l] != s[r]) {
			is_pseudo_palindrome = false;
			break;
		}

		l++;
		r--;
	}

	if (!is_pseudo_palindrome)
		return false;

	return true;
}

void solution() {
	int left = 0;
	int right = s.size() - 1;

	while (left < right) {
		if (s[left] != s[right]) {
			if (!check(left, right)) {
				cout << 2 << "\n";
			}
			else {
				cout << 1 << "\n";
			}
		
			return;
		}

		left++;
		right--;
	}

	cout << 0 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}