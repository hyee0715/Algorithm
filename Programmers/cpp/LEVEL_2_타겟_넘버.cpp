#include <string>
#include <vector>

using namespace std;

vector<char> opList;
int count = 0;

int calculate(vector<int>& numbers, int target) {
	int sum = 0;

	for (int i = 0; i < numbers.size(); i++) {
		if (opList[i] == '+') {
			sum += numbers[i];
		}
		else {
			sum -= numbers[i];
		}
	}

	return sum;
}

void dfs(int cnt, vector<int>& numbers, int target, vector<int>& op) {
	if (cnt == numbers.size()) {
		int result = calculate(numbers, target);

		if (result == target) {
			count++;
		}
	}
	else {
		for (int i = 0; i < op.size(); i++) {
			opList.push_back(op[i]);
			dfs(cnt + 1, numbers, target, op);
			opList.pop_back();
		}
	}
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	vector<int> op = { '+', '-' };

	dfs(0, numbers, target, op);

	answer = count;
	return answer;
}
