#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
set<int> st;
vector<int> v1, v2;

void input() {
	cin >> n;
	
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v1.push_back(a);
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> a;
		v2.push_back(a);
	}
}

void solution() {
	for (int i = 0; i < v1.size(); i++) {
		st.insert(v1[i]);
	}

	for (int i = 0; i < v2.size(); i++) {
		if (st.find(v2[i]) != st.end()) {
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}