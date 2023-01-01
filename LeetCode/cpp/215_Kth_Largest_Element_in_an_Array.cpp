class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>> hi;
		int answer;

		for (int n : nums) {
			hi.push(n);
		}

		for (int i = 0; i < k; i++) {
			answer = hi.top();
			hi.pop();
		}

		return answer;
	}
};