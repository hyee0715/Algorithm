#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int answer = 0;
string s;
unordered_map<int, int> um;

void initialize() {
	um.clear();
}

void input() {
	cin >> s;
}

void solution() {
	for (int i = 0; i < s.size(); i++) {
		um[s[i]]++;
	}

	answer = um.size();

	cout << answer << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		initialize();
		input();
		solution();
	}

	return 0;
}