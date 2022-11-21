#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n;
char digit;
unordered_map<char, int> um;

void input() {
	cin >> n >> digit;
}

void solution() {
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);

		for (int j = 0; j < s.size(); j++) {
			um[s[j]]++;
		}
	}

	cout << um[digit];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}