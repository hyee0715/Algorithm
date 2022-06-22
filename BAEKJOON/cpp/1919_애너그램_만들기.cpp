#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, int> um1, um2;
string s1, s2;
int answer = 0;

void input() {
	cin >> s1 >> s2;
}

void solution() {
	for (int i = 0; i < s1.size(); i++) {
		um1[s1[i]]++;
	}

	for (int i = 0; i < s2.size(); i++) {
		um2[s2[i]]++;
	}

	for (auto um : um1) {
		if (um1[um.first] != um2[um.first]) {
			answer += abs(um1[um.first] - um2[um.first]);
			um1[um.first] = 0;
			um2[um.first] = 0;
		}
	}

	for (auto um : um2) {
		if (um1[um.first] != um2[um.first]) {
			answer += abs(um1[um.first] - um2[um.first]);
			um1[um.first] = 0;
			um2[um.first] = 0;
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