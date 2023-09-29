class Solution {
public:
	int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		int answer = 0;
		map<int, int> mp;

		for (vector<int> point : points) {
			mp[point[0]]++;
		}

		int prev = -1;

		for (pair<int, int> p : mp) {
			if (prev == -1) {
				prev = p.first;
				continue;
			}

			answer = max(answer, p.first - prev);
			prev = p.first;
		}

		return answer;
	}
};