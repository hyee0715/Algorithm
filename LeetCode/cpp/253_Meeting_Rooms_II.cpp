class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		int answer = -1;

		vector<int> nums(1000001, 0);

		for (vector<int> interval : intervals) {
			int start = interval[0];
			int end = interval[1];

			nums[start]++;
			nums[end]--;
		}


		for (int i = 1; i < 1000001; i++) {
			nums[i] = nums[i - 1] + nums[i];

			answer = max(answer, nums[i]);
		}

		return answer;
	}
};