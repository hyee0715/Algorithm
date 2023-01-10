class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		int answer = 0;

		while (stones.size() > 1) {
			sort(stones.begin(), stones.end());

			int heaviest1 = stones[stones.size() - 1];
			int heaviest2 = stones[stones.size() - 2];

			stones.pop_back();
			stones.pop_back();

			if (heaviest1 != heaviest2) {
				stones.push_back(heaviest1 - heaviest2);
			}
		}

		if (stones.size() == 1) {
			answer = stones[stones.size() - 1];
		}

		return answer;
	}
};