class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		if (nums.size() == 1) {
			return 1;
		}

		int answer = INT_MAX;
		unordered_map<int, int> numsMap;
		int maxCnt = 0, cnt = 0;

		for (int n : nums) {
			numsMap[n]++;
		}

		for (pair<int, int> map : numsMap) {
			maxCnt = max(maxCnt, map.second);
		}

		unordered_map<int, int> curMap;
		int left = 0, right = 0;
		curMap[nums[left]]++;

		while (left < nums.size() - 1 || right < nums.size() - 1) {
			cnt = 0;
			for (auto map : curMap) {
				cnt = max(cnt, map.second);
			}

			if (cnt < maxCnt) {
				right++;

				if (right >= nums.size()) {
					break;
				}

				curMap[nums[right]]++;
			}
			else {
				answer = min(answer, right - left + 1);
				curMap[nums[left]]--;
				left++;
			}
		}

		return answer;
	}
};