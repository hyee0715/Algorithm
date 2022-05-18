#include <iostream>
#include <string>
using namespace std;

int answer = 0;
string s;
char map[8][8];

void input() {
	for (int i = 0; i < 8; i++) {
		cin >> s;
		
		for (int j = 0; j < 8; j++) {
			map[i][j] = s[j];
		}
	}
}

void solution() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {
				if (map[i][j] == 'F')
					answer++;
			}
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