#include <iostream>
#include <string>
using namespace std;

string a, b;
long long answer = 0;

void input() {
	cin >> a >> b;
}

void solution() {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			answer += ((a[i] - '0') * (b[j] - '0'));
		}
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}