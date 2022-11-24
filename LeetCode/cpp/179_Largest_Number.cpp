class Solution {
public:
	static bool compare(string a, string b) {
		if (a + b > b + a) {
			return true;
		}

		return false;
	}

	bool all_zero(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				return false;
			}
		}

		return true;
	}

	string largestNumber(vector<int>& nums) {
		if (all_zero(nums) == true) {
			return "0";
		}

		vector<string> v;
		string answer;

		for (int num : nums) {
			v.push_back(to_string(num));
		}

		sort(v.begin(), v.end(), compare);

		for (string s : v) {
			answer += s;
		}

		return answer;
	}
};