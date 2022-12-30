#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string s;
unordered_map<char, int> um;

void input() {
	cin >> s;
}

bool is_odd(unordered_map<char, int> um) {
	for (auto m : um) {
		if (m.second % 2 == 0) {
			return false;
		}
	}

	return true;
}

bool is_even(unordered_map<char, int> um) {
	for (auto m : um) {
		if (m.second % 2 != 0) {
			return false;
		}
	}

	return true;
}

void solution() {
	for (int i = 0; i < s.length(); i++) {
		um[s[i]]++;
	}

	if (is_odd(um)) {
		cout << 1;
		return;
	}

	if (is_even(um)) {
		cout << 0;
		return;
	}

	cout << "0/1";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solution();

	return 0;
}