class Solution {
public:
	int minimumOperations(vector<int>& nums) {
		priority_queue<int, vector<int>, greater<int>> lo, lo2;
		int answer = 0;

		for (int n : nums) {
			lo.push(n);
		}

		while (!lo.empty()) {
			int min_num = lo.top();
			lo.pop();

			while (min_num == 0 && !lo.empty()) {
				min_num = lo.top();
				lo.pop();
			}

			if (min_num == 0 && lo.empty()) {
				break;
			}

			answer++;

			while (!lo.empty()) {
				lo2.push(lo.top() - min_num);
				lo.pop();
			}

			while (!lo2.empty()) {
				lo.push(lo2.top());
				lo2.pop();
			}
		}

		return answer;
	}
};