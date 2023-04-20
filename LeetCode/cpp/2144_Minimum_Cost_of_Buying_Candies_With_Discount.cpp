class Solution {
public:
	int minimumCost(vector<int>& cost) {
		int answer = 0;

		sort(cost.begin(), cost.end(), greater<>());

		for (int i = 0; i < cost.size(); i++) {
			if (i % 3 == 2) {
				continue;
			}

			answer += cost[i];
		}

		return answer;
	}
};