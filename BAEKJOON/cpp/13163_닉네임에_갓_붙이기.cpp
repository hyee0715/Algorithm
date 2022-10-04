#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;
string s, answer;

void input() {
	v.clear();
	s.clear();
	answer.clear();
	cin.ignore();

	getline(cin, s);
}

void solution() {
	string temp;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			v.push_back(temp);
			temp.clear();
		}
		else {
			temp += s[i];
		}
	}

	if (!temp.empty()) {
		v.push_back(temp);
		temp.clear();
	}

	answer += "god";

	for (int i = 1; i < v.size(); i++) {
		answer += v[i];
	}

	cout << answer << "\n";
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
	}

	return 0;
}