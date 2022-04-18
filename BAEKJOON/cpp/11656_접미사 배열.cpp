#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string s;
vector<string> answer;

void input() {
	cin >> s;
}

void solution() {
	string s_suffix;

	int size = s.size();
	for (int i = 0; i < size; i++) {
		s_suffix = s.substr(i, size - i);

		answer.push_back(s_suffix);
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
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