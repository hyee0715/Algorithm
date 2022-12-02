#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s, rev_s;

void input() {
	cin >> s;
}

void solution() {
	rev_s = s;
	reverse(rev_s.begin(), rev_s.end());

	int sum = stoi(s) + stoi(rev_s);

	string str_sum = to_string(sum);
	string rev_str_sum = str_sum;
	reverse(rev_str_sum.begin(), rev_str_sum.end());

	if (str_sum == rev_str_sum) {
		cout << "YES" << "\n";
		return;
	}

	cout << "NO" << "\n";
}

int main()
{
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