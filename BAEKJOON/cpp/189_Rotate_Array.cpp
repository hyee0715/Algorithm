class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		deque<int> dq;

		for (int n : nums) {
			dq.push_back(n);
		}

		for (int i = 0; i < k; i++) {
			int num = dq.back();
			dq.pop_back();

			dq.push_front(num);
		}

		nums.clear();

		while (!dq.empty()) {
			nums.push_back(dq.front());
			dq.pop_front();
		}
	}
};