#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

string s;
unordered_map<char, int> um;

void input() {
	cin >> s;
}

void solution() {
	for (int i = 0; i < s.length(); i++) {
		um[s[i]]++;
	}

	vector<int> temp;

	for (auto m : um) {
		temp.push_back(m.second);
	}

	for (int i = 0; i < temp.size(); i++) {
		temp[i] = (temp[i] % 2);
	}

	um.clear();

	for (int i = 0; i < temp.size(); i++) {
		um[temp[i]]++;
	}

	if (um.size() == 1) {
		for (auto m : um) {
			if (m.first == 0) {
				cout << 0;
				return;
			}

			cout << 1;
			return;
		}
	}

	cout << 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}