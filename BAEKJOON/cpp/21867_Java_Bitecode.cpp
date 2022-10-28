#include <iostream>
#include <string>
using namespace std;

int n;
string s, answer;

void input() {
	cin >> n;
	cin >> s;
}

void solution() { 
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'J' || s[i] == 'A' || s[i] == 'V') {
			continue;
		}

		answer += s[i];
	}

	if (answer.empty()) {
		cout << "nojava";
	}
	else {
		cout << answer;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}