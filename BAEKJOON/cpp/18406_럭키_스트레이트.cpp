#include <iostream>
#include <string>
using namespace std;

string s;

void input() {
	cin >> s;
}

void solution() {
	int mid = s.size() / 2;

	string s1 = s.substr(0, mid);
	string s2 = s.substr(mid, mid);

	int n1 = 0, n2 = 0;
	for (int i = 0; i < s1.size(); i++) {
		n1 += (int)s1[i];
		n2 += (int)s2[i];
	}

	if (n1 == n2)
		cout << "LUCKY";
	else
		cout << "READY";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}