#include <iostream>
#include <set>
#include <string>
#include <vector>

#define MAX 10
using namespace std;

int n, k;
vector<string> cards, v;
vector<bool> visit(MAX, false);
set<string> st;

void input() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		cards.push_back(a);
	}
}

void find_integer(vector<string> v) {
	string s;

	for (int i = 0; i < v.size(); i++)
		s += v[i];

	if (st.find(s) == st.end())
		st.insert(s);
}

void dfs(int cnt) { //순열
	if (cnt == k) {
		find_integer(v);
	}
	else {
		for (int i = 0; i < cards.size(); i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			v.push_back(cards[i]);
			dfs(cnt + 1);
			visit[i] = false;
			v.pop_back();
		}
	}
}

void solution() {
	dfs(0);

	cout << st.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}