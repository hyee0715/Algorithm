class Solution {
public:
	int minimumCardPickup(vector<int>& cards) {
		int answer = INT_MAX;
		unordered_map<int, vector<int>> um; //number, index

		for (int i = 0; i < cards.size(); i++) {
			if (um.count(cards[i])) {
				vector<int> v = um[cards[i]];
				answer = min(answer, i - v[v.size() - 1] + 1);
			}

			um[cards[i]].push_back(i);
		}

		if (answer == INT_MAX) {
			answer = -1;
		}

		return answer;
	}
};