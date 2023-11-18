#include <iostream>
#include <set>
#include <string>
using namespace std;

set<char> st;
string s;

void initialize() {
	st.clear();
}

void input() {
	cin >> s;
}

void solution() {
	for (int i = 0; i < s.length(); i++) {
		st.insert(s[i]);
	}

	cout << st.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		initialize();
		input();

		cout << "#" << i << " ";
		solution();
		cout << "\n";
	}

	return 0;
}