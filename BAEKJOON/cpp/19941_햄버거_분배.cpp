#include <iostream>
#include <string>

using namespace std;

int n, k, answer = 0;
string s;

void input() {
	cin >> n >> k >> s;
}

void solution() {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'P') {
			for (int j = i - k; j <= i + k; j++) {
				if (j < 0 || j > n - 1) continue;
				
				if (s[j] == 'H') {
					answer++;
					s[j] = '.';
					break;
				}
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