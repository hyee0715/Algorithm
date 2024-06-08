class Solution {
public:
	vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
		vector<vector<int>> answer;

		for (vector<int> interval : intervals) {
			int start = interval[0];
			int end = interval[1];

			//범위 완전히 안에 들어가는 경우
			if (start < toBeRemoved[0] && end > toBeRemoved[1]) {
				answer.push_back({ start, toBeRemoved[0] });
				answer.push_back({ toBeRemoved[1], end });
			}
			else if (start < toBeRemoved[0] && end > toBeRemoved[0] && end <= toBeRemoved[1]) {
				//왼쪽 걸치는 경우
				answer.push_back({ start, toBeRemoved[0] });
			}
			else if (start >= toBeRemoved[0] && start < toBeRemoved[1] && end > toBeRemoved[1]) {
				//오른쪽 걸치는 경우
				answer.push_back({ toBeRemoved[1], end });
			}
			else if ((start < toBeRemoved[0] && end < toBeRemoved[0]) || (start > toBeRemoved[1] && end > toBeRemoved[1])) {
				//완전 밖인 경우
				answer.push_back({ start, end });
			}
			else if (start > toBeRemoved[0] && start < toBeRemoved[1] && end > toBeRemoved[0] && end < toBeRemoved[1]) {
				//interval이 toBeRemoved안에 들어가는경우
				continue;
			}
		}

		return answer;
	}
};