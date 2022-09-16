#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int n, cnt = 0;
stack<char> st;
vector<string> v;

void input() {
	cin >> n;
	
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
}

void st_clear() {
	while (!st.empty()) {
		st.pop();
	}
}

void solution() {
	for (int i = 0; i < v.size(); i++) {
		st_clear();

		for (int j = 0; j < v[i].size(); j++) {
			if (st.empty()) {
				st.push(v[i][j]);
			}
			else if (st.top() != v[i][j]) {
				st.push(v[i][j]);
			}
			else {
				st.pop();
			}
		}

		if (st.empty())
			cnt++;
	}

	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}