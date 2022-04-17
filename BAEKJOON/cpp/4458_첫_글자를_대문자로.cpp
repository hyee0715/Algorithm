#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s;
vector<string> v;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		v.push_back(s);
	}
}

void solution() {
	for (int i = 0; i < v.size(); i++) {
		 toupper(v[i][0]);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
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