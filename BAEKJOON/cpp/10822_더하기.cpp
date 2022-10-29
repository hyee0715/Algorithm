#include <iostream>
#include <string>
using namespace std;

string s;
int answer = 0;

void input() {
	cin >> s;
}

void solution() {
	string temp;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') {
			answer += stoi(temp);
			temp.clear();
		}
		else {
			temp += s[i];
		}
	}

	if (!temp.empty()) {
		answer += stoi(temp);
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