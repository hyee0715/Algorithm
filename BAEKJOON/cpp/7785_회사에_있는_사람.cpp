#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

void solution() {
	unordered_set<string> st;
	
	int n;
	cin >> n;

	string a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		if (b == "enter") {
			st.insert(a);
		}
		else {
			st.erase(a);
		}
	}

	vector<string> names;

	for (string name : st) {
		names.push_back(name);
	}

	sort(names.begin(), names.end(), greater<>());

	for (string name : names) {
		cout << name << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}