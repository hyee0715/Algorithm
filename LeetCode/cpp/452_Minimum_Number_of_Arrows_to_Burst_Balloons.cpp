class Solution {
public:
	int getShots(vector<vector<int>>& points, int idx, int answer) {
		if (idx >= points.size() - 1) {
			return answer + 1;
		}

		pair<int, int> current = { max(points[idx][0], points[idx + 1][0]), min(points[idx][1], points[idx + 1][1]) };

		if (current.first > current.second) {
			answer++;
		}
		else {
			points[idx + 1][0] = current.first;
			points[idx + 1][1] = current.second;
		}

		return answer = getShots(points, idx + 1, answer);
	}

	int findMinArrowShots(vector<vector<int>>& points) {
		int answer = 0;

		sort(points.begin(), points.end());

		answer = getShots(points, 0, answer);

		return answer;
	}
};