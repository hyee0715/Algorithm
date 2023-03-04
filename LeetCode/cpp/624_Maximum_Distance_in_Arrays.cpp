class Solution {
public:
	int maxDistance(vector<vector<int>>& arrays) {
		int answer = -1;
		int minNum = arrays[0][0], maxNum = arrays[0][arrays[0].size() - 1];

		for (int i = 1; i < arrays.size(); i++) {
			int newDistance = abs(minNum - arrays[i][arrays[i].size() - 1]);

			if (answer < newDistance) {
				answer = newDistance;
			}

			newDistance = abs(arrays[i][0] - maxNum);

			if (answer < newDistance) {
				answer = newDistance;
			}

			if (minNum > arrays[i][0]) {
				minNum = arrays[i][0];
			}

			if (maxNum < arrays[i][arrays[i].size() - 1]) {
				maxNum = arrays[i][arrays[i].size() - 1];
			}
		}

		return answer;
	}
};