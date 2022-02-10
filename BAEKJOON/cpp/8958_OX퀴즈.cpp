#include <iostream>
#include <string>
#include <vector>

using namespace std;

int tc;
vector<string> vec;
int o_cnt, sum;
vector<int> answer;

void input() {
	cin >> tc;

	string s;
	for (int i = 0; i < tc; i++) {
		cin >> s;
		vec.push_back(s);
	}
}

void solution() {
	for (int i = 0; i < vec.size(); i++) {
		o_cnt = 0;
		sum = 0;

		for (int j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] == 'O') {
				o_cnt++;
				sum += o_cnt;
			}
			else {
				o_cnt = 0;
			}
		}

		answer.push_back(sum);
	}

	// print answer
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