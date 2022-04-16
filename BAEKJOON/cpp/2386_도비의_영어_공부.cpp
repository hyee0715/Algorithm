#include <iostream>
#include <string>
#include <vector>
using namespace std;

char c;
string s;
vector<pair<char, int> > answer;

void solution() {
	while (1) {
		cin >> c;

		if (c == '#') break;

		getline(cin, s);

		int cnt = 0;

		for (int i = 0; i < s.size(); i++) {
			if (tolower(s[i]) == c)
				cnt++;
		}

		answer.push_back({ c, cnt });
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].first << " " << answer[i].second << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}