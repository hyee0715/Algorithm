#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int sum = 0;

void input() {
	cin >> n >> s;
}

void solution() {
	for (int i = 0; i < s.size(); i++) {
		sum += (s[i] - '0');
	}

	cout << sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}