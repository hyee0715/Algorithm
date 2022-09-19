#include <iostream>
#include <string>
using namespace std;

string a, b, c, d, s1, s2;

void input() {
	cin >> a >> b >> c >> d;
}

void solution() {
	s1 = a + b;
	s2 = c + d;

	long long n1 = stoll(s1);
	long long n2 = stoll(s2);

	cout << n1 + n2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}