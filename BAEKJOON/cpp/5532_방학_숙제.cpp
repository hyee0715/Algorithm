#include <iostream>
using namespace std;

int l, a, b, c, d;

void input() {
	cin >> l >> a >> b >> c >> d;
}

void solution() {
	int lang = a / c;
	int math = b / d;

	if (a % c != 0)
		lang++;

	if (b % d != 0)
		math++;

	if (lang > math) 
		cout << l - lang;
	else 
		cout << l - math;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}