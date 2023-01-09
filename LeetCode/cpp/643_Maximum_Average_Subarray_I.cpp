class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double answer = INT_MIN;

		double sum = 0;
		for (int i = 0; i < k; i++) {
			sum += nums[i];
		}

		answer = max(answer, sum / k);

		int left = 0;
		int right = k - 1;

		while (left <= right && right < nums.size() - 1) {
			sum -= nums[left];
			left++;
			right++;
			sum += nums[right];

			answer = max(answer, sum / k);
		}

		return answer;
	}
};