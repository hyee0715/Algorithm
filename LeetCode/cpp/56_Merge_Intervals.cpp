class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> answer;
		vector<int> v(2, -1);

		if (intervals.size() == 1) {
			v[0] = intervals[0][0];
			v[1] = intervals[0][1];

			answer.push_back(v);
			return answer;
		}

		sort(intervals.begin(), intervals.end());

		v[0] = intervals[0][0];
		v[1] = intervals[0][1];

		for (int i = 1; i < intervals.size(); i++) {
			if (v[1] < intervals[i][0]) {
				answer.push_back(v);

				v[0] = intervals[i][0];
				v[1] = intervals[i][1];
			}

			if (v[1] >= intervals[i][0] && v[1] <= intervals[i][1]) {
				v[1] = intervals[i][1];
			}

			if (i == intervals.size() - 1) {
				answer.push_back(v);
			}
		}

		return answer;
	}
};