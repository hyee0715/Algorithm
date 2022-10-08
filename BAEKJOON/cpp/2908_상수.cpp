#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a, b;
string s1, s2;

void input() {
	cin >> s1 >> s2;
}

void solution() {
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	a = stoi(s1);
	b = stoi(s2);

	if (a > b)
		cout << a;
	else
		cout << b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}