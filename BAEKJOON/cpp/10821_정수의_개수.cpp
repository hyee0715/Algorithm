#include <iostream>
#include <string>
using namespace std;

string s;
int answer = 1;

void input() {
	cin >> s;
}

void solution() {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',')
			answer++;
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