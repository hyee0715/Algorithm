class Solution {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		int answer = 0;
		priority_queue<int, vector<int>, greater<>> pq(nums.begin(), nums.end());

		while (k > 0) {
			int n = pq.top();
			pq.pop();

			pq.push(-1 * n);

			k--;
		}

		while (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}

		return answer;
	}
};