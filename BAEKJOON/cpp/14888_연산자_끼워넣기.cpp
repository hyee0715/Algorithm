#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> nums;
vector<int> ops;
int maxNum = -1000000001;
int minNum = 1000000000;

void input() {
	cin >> n;

	int a;

	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
	}

	for (int i = 0; i < 4; i++) {
		cin >> a;
		ops.push_back(a);
	}
}

vector<char> getOperators() {
	vector<char> ret;

	for (int i = 0; i < ops[0]; i++) {
		ret.push_back('+');
	}

	for (int i = 0; i < ops[1]; i++) {
		ret.push_back('-');
	}

	for (int i = 0; i < ops[2]; i++) {
		ret.push_back('*');
	}

	for (int i = 0; i < ops[3]; i++) {
		ret.push_back('/');
	}

	return ret;
}

int calculate(vector<char>& v) {
	int result = nums[0];

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == '+') {
			result += nums[i + 1];
		}
		else if (v[i] == '-') {
			result -= nums[i + 1];
		}
		else if (v[i] == '*') {
			result *= nums[i + 1];
		}
		else {
			if (result < 0) {
				result *= -1;
				result /= nums[i + 1];
				result *= -1;
			}
			else {
				result /= nums[i + 1];
			}
		}
	}

	return result;
}

void dfs(int cnt, vector<char>& operators, vector<bool>& visit, vector<char>& v) {
	if (cnt == operators.size()) {
		maxNum = max(maxNum, calculate(v));
		minNum = min(minNum, calculate(v));
	}
	else {
		for (int i = 0; i < operators.size(); i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			v.push_back(operators[i]);
			dfs(cnt + 1, operators, visit, v);
			visit[i] = false;
			v.pop_back();
		}
	}
}

void solution() {
	vector<char> operators = getOperators();

	vector<bool> visit(operators.size(), false);
	vector<char> v;

	dfs(0, operators, visit, v);

	cout << maxNum << "\n" << minNum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}
