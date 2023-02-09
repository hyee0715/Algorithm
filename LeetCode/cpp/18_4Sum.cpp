class Solution {
public:
	vector<vector<int>> twoSum(vector<int>& nums, int target, int first, int second) {
		vector<vector<int>> answer;

		int left = second + 1, right = nums.size() - 1;

		while (left < right) {
			long long sum = 0;
			sum += nums[first];
			sum += nums[second];
			sum += nums[left];
			sum += nums[right];

			if (sum == target) {
				vector<int> v;
				v.push_back(nums[first]);
				v.push_back(nums[second]);
				v.push_back(nums[left]);
				v.push_back(nums[right]);

				answer.push_back(v);

				left++;
				right--;
			}
			else if (sum < target) {
				left++;
			}
			else {
				right--;
			}
		}

		return answer;
	}

	vector<vector<int>> threeSum(vector<int>& nums, int target, int first) {
		vector<vector<int>> answer;

		for (int i = first + 1; i < nums.size() - 1; i++) {
			vector<vector<int>> v = twoSum(nums, target, first, i);

			for (vector<int> list : v) {
				answer.push_back(list);
			}
		}

		return answer;
	}

	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> answer;

		if (nums.size() == 1 && target == nums[0]) {
			return answer;
		}

		set<vector<int>> st;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; i++) {
			vector<vector<int>> v = threeSum(nums, target, i);

			for (vector<int> list : v) {
				st.insert(list);
			}
		}

		for (auto s : st) {
			answer.push_back(s);
		}

		return answer;
	}
};