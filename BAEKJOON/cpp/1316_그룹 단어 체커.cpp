#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#define MAX 100
using namespace std;

int n, answer = 0;
vector<string> vec;
bool alphabet[26];

void input() {
	cin >> n;

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		vec.push_back(s);
	}
}

void solution() {
	for (int i = 0; i < vec.size(); i++) {
		memset(alphabet, false, sizeof(alphabet));
		alphabet[vec[i][0] - 'a'] = true;

		if (vec[i].size() != 1) {
			for (int j = 1; j < vec[i].size(); j++) {
				if (vec[i][j] != vec[i][j - 1]) {
					if ((alphabet[vec[i][j] - 'a']) == false) {
						alphabet[vec[i][j] - 'a'] = true;
					}
					else {
						break;
					}
				}

				if (j == (vec[i].size() - 1)) {
					answer++;
				}
			}
		}
		else {
			answer++;
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