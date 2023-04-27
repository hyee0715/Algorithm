class Solution {
public:
	int maxIceCream(vector<int>& costs, int coins) {
		int answer = 0;
		map<int, int> um;

		for (int cost : costs) {
			um[cost]++;
		}

		for (auto m : um) {
			if (coins >= m.first) {
				for (int i = 0; i < m.second; i++) {
					if (coins < m.first) {
						break;
					}

					coins -= m.first;
					answer++;
				}
			}
		}

		return answer;
	}
};