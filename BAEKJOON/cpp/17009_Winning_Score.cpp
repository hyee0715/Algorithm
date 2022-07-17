#include <iostream>
using namespace std;

int s1 = 0, s2 = 0;

void input() {
	int a, b, c;
	
	cin >> a >> b >> c;
	s1 += a * 3;
	s1 += b * 2;
	s1 += c * 1;

	cin >> a >> b >> c;
	s2 += a * 3;
	s2 += b * 2;
	s2 += c * 1;
}

void solution() {
	if (s1 > s2)
		cout << "A";
	else if (s1 < s2)
		cout << "B";
	else
		cout << "T";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}