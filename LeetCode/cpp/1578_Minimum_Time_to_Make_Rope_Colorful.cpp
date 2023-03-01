class Solution {
public:
	int minCost(string colors, vector<int>& neededTime) {
		int answer = 0, sameCnt = 0;
		priority_queue<int, vector<int>, greater<>> lo;

		for (int i = 0; i < colors.length() - 1; i++) {
			if (colors[i] != colors[i + 1]) {
				if (!lo.empty()) {
					while (sameCnt > 1) {
						answer += lo.top();
						lo.pop();

						sameCnt--;
					}
				}

				while (!lo.empty()) {
					lo.pop();
				}

				sameCnt = 0;

				continue;
			}

			if (lo.empty()) {
				lo.push(neededTime[i]);
				sameCnt++;
			}

			lo.push(neededTime[i + 1]);
			sameCnt++;
		}

		if (!lo.empty() && sameCnt > 0) {
			while (sameCnt > 1) {
				answer += lo.top();
				lo.pop();
				sameCnt--;
			}
		}

		return answer;
	}
};