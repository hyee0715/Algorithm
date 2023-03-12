class Solution {
public:
	int maximumProduct(vector<int>& nums, int k) {
		int answer = 1;

		priority_queue<int, vector<int>, greater<>> lo;

		for (int n : nums) {
			lo.push(n);
		}

		while (k > 0) {
			int n = lo.top();
			lo.pop();
			n++;

			lo.push(n);
			k--;
		}

		while (!lo.empty()) {
			long long n = lo.top() % 1000000007;
			answer = (answer * n) % 1000000007;
			lo.pop();
		}

		return answer;
	}
};