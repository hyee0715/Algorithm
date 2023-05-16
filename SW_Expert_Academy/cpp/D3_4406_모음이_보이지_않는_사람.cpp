#include <iostream>
#include <string>
#include <set>
using namespace std;

string s;
set<char> st;

void input() {
	cin >> s;
}

void solution() {
	st.insert('a');
	st.insert('e');
	st.insert('i');
	st.insert('o');
	st.insert('u');

	string answer;

	for (int i = 0; i < s.length(); i++) {
		if (st.find(s[i]) == st.end()) {
			answer += s[i];
		}
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		input();

		cout << "#" << i << " ";

		solution();

		cout << "\n";
	}

	return 0;
}