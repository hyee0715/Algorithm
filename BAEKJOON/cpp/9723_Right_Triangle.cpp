#include <iostream>
#include <string>
using namespace std;

int a, b, c;
string answer;

void input() {
	cin >> a >> b >> c;
}

void solution() {
	if (a > b && a > c) {
		if (b * b + c * c == a * a)
			answer = "YES";
		else
			answer = "NO";
	}
	else if (b > a && b > c) {
		if (a * a + c * c == b * b)
			answer = "YES";
		else
			answer = "NO";
	}
	else if (c > a && c > b) {
		if (a * a + b * b == c * c)
			answer = "YES";
		else
			answer = "NO";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		input();
		solution();
		cout << "Case #" << i + 1 << ": " << answer << "\n";
	}

	return 0;
}