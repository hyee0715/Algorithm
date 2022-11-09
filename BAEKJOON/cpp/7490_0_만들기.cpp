#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, limit;
vector<int> nums;
vector<char> operations;
vector<string> answer;
char oper[3] = { ' ', '+', '-' };

void initialize() {
	nums.clear();
	operations.clear();
	answer.clear();
}

void input() {
	cin >> n;
}

void check() {
	string cal;
	cal += (nums[0] + '0');

	for (int i = 0; i < operations.size(); i++) {
		cal += operations[i];
		cal += (nums[i + 1] + '0');
	}

	for (int i = 0; i < cal.size(); i++) {
		if (cal[i] == ' ') {
			cal.erase(i, 1);
		}
	}

	int sum = 0;
	string temp;
	int idx = 0;
	for (int i = 0; i < cal.size(); i++) {
		if (cal[i] != '+' && cal[i] != '-') {
			temp += cal[i];
		}
		else {
			idx = i;
			break;
		}
	}

	sum += stoi(temp);
	temp.clear();
	char op = cal[idx];

	for (int i = idx + 1; i < cal.size(); i++) {
		if (cal[i] == '+' || cal[i] == '-') {
			if (op == '+') {
				sum += stoi(temp);
				temp.clear();
				op = cal[i];
			}
			else if (op == '-') {
				sum -= stoi(temp);
				temp.clear();
				op = cal[i];
			}
		}
		else {
			temp += cal[i];
		}
	}
	
	if (!temp.empty()) {
		if (op == '+') {
			sum += stoi(temp);
			temp.clear();
		}
		else if (op == '-') {
			sum -= stoi(temp);
			temp.clear();
		}
	}

	if (sum == 0) {
		temp.clear();
		string s;

		for (int i = 0; i < cal.size(); i++) {
			if (cal[i] == '+' || cal[i] == '-') {
				temp += cal[i];
				s += temp;
				temp.clear();
			}
			else {
				if (!temp.empty()) {
					temp += " ";
				}

				temp += cal[i];
			}
		}
	
		if (!temp.empty()) {
			s += temp;
			temp.clear();
		}

		answer.push_back(s);
	}
}

void dfs(int cnt) {
	if (cnt == limit) {
		check();

		return;
	}
	else {
		for (int i = 0; i < 3; i++) {
			operations.push_back(oper[i]);
			dfs(cnt + 1);
			operations.pop_back();
		}
	}
}

void solution() {
	for (int i = 1; i <= n; i++) {
		nums.push_back(i);
	}

	limit = nums.size() - 1;

	dfs(0);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		initialize();
		input();
		solution();
		
		cout << "\n";
	}

	return 0;
}