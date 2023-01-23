class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int first = 0, second = 0;

		for (int num : nums) {
			first = ~second & (num ^ first);
			second = ~first & (num ^ second);
		}

		return first;
	}
};