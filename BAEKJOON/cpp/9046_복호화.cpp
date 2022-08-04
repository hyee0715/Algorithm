#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string s;

void input() {
	getline(cin, s);
}

void solution() {
	vector<int> alphabet(26, 0);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			alphabet[s[i] - 'a']++;
		}
	}

	vector<pair<int, char>> v;

	for (int i = 0; i < alphabet.size(); i++) {
		v.push_back({ alphabet[i], i + 'a' });
	}

	sort(v.begin(), v.end(), greater<>());
	
	if (v[0].first == v[1].first) {
		cout << "?\n";
	}
	else {
		cout << v[0].second << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	cin.ignore();

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}