#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, maxNum, minNum;
vector<int> nums, ops;
vector<char> operators, v;
vector<bool> visit;

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

vector<char> makeOps() {
	vector<char> ret;
	char op[] = {'+', '-', '*', '/'};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < ops[i]; j++) {
			ret.push_back(op[i]);
		}
	}

	return ret;
}

int calculate() {
	vector<int> calNums;
	vector<char> calOps;

	int idx = 0;
	calNums.push_back(nums[idx++]);

	//곱하기, 나누기 먼저 계산
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != '*' && v[i] != '/') {
			calOps.push_back(v[i]);
			calNums.push_back(nums[idx++]);
		}
		else {
			int cur = calNums[calNums.size() - 1];
			calNums.pop_back();

			if (v[i] == '*') {
				calNums.push_back(cur * nums[idx++]);
			}
			else {
				calNums.push_back(cur / nums[idx++]);
			}
		}
	}

	//더하기, 빼기 계산
	idx = 0;
	int result = calNums[idx++];

	for (int i = 0; i < calOps.size(); i++) {
		if (calOps[i] == '+') {
			result += calNums[idx++];
		}
		else {
			result -= calNums[idx++];
		}
	}

	return result;
}

void dfs(int cnt) {
	if (cnt == n - 1) {
		int result = calculate();

		minNum = min(minNum, result);
		maxNum = max(maxNum, result);

		return;
	}

	for (int i = 0; i < operators.size(); i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		v.push_back(operators[i]);
		dfs(cnt + 1);
		visit[i] = false;
		v.pop_back();
	}
}

void solution() {
	operators = makeOps();
	visit.assign(operators.size(), false);

	minNum = 1000000001;
	maxNum = -1000000001;
	
	//순열
	dfs(0);

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