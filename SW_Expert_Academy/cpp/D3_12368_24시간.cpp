#include <iostream>
using namespace std;

int answer = 0;
int a = 0, b = 0;

void initialize() {
	answer = 0;
}

void input() {
	cin >> a >> b;
}

void solution() {
	answer += a;
	answer += b;

	answer = answer % 24;

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		initialize();
		input();
		cout << "#" << i << " ";
		solution();
		cout << "\n";
	}

	return 0;
}