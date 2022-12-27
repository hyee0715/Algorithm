class Solution {
public:
	int longestSquareStreak(vector<int>& nums) {
		int answer = -1;

		sort(nums.begin(), nums.end());

		set<int> numsSet;

		for (int n : nums) {
			numsSet.insert(n);
		}

		for (int i = 0; i < nums.size(); i++) {
			int cnt = 1;
			int n = nums[i];

			while (1) {
				if ((long long)n * n > 100000) {
					break;
				}

				n = n * n;

				if (numsSet.find(n) == numsSet.end()) {
					break;
				}

				if (numsSet.find(n) != numsSet.end()) {
					cnt++;

					if (cnt > 1) {
						answer = max(answer, cnt);
					}
				}
			}
		}

		return answer;
	}
};