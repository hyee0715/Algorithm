#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int tc, cnt = 1;
long long a, b, c;

void input() {
	cin >> a >> b >> c;
}

bool find_right_triangle() {
	if (pow(a, 2) == pow(b, 2) + pow(c, 2))
		return true;

	if (pow(b, 2) == pow(a, 2) + pow(c, 2))
		return true;

	if (pow(c, 2) == pow(a, 2) + pow(b, 2))
		return true;

	return false;
}

void solution() {
	if (find_right_triangle())
		cout << "Scenario #" << cnt << ":\n" << "yes\n";
	else
		cout << "Scenario #" << cnt << ":\n" << "no\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tc;

	while (cnt <= tc) {
		input();
		solution();

		cout << "\n";
		cnt++;
	}
	
	return 0;
}