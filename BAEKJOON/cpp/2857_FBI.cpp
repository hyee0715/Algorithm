#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;
vector<int> answer;

void input() {
	string s;

	for (int i = 0; i < 5; i++) {
		cin >> s;
		v.push_back(s);
	}
}

void solution() {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == 'F') {
				if (v[i][j + 1] == 'B' && v[i][j + 2] == 'I') {
					answer.push_back(i + 1);
					break;
				}
			}
		}
	}

	if (answer.empty()) {
		cout << "HE GOT AWAY!";
	}
	else {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
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