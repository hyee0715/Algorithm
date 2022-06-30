#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string s;
unordered_map<char, int> um;

void input() {
	cin >> s;
}

void make_map() {
	int num = 3;
	int cnt = 0;

	for (int i = 0; i < 15; i++) {
		um[char('A' + i)] = num;
		cnt++;

		if (cnt == 3) {
			num++;
			cnt = 0;
		}
	}

	um['P'] = 8;
	um['Q'] = 8;
	um['R'] = 8;
	um['S'] = 8;

	um['T'] = 9;
	um['U'] = 9;
	um['V'] = 9;

	um['W'] = 10;
	um['X'] = 10;
	um['Y'] = 10;
	um['Z'] = 10;
}

void solution() {
	make_map();

	int sum = 0;

	for (int i = 0; i < s.size(); i++) {
		sum += um[s[i]];
	}

	cout << sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solution();

	return 0;
}