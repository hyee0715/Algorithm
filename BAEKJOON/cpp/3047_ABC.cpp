#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
string s;
int a, b, c; // a < b < c;

void input() {
	int n;

	for (int i = 0; i < 3; i++) {
		cin >> n;
		v.push_back(n);
	}

	cin >> s;
}

void solution() {
	sort(v.begin(), v.end());

	a = v[0];
	b = v[1];
	c = v[2];

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A')
			cout << a;
		else if (s[i] == 'B')
			cout << b;
		else
			cout << c;

		cout << " ";
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