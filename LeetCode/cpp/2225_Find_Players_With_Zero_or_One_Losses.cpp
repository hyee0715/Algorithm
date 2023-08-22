class Solution {
public:
	vector<vector<int>> findWinners(vector<vector<int>>& matches) {
		vector<vector<int>> answer(2);
		unordered_map<int, int> lose;

		for (vector<int> match : matches) {
			lose[match[1]]++;
		}

		for (auto m : lose) {
			if (m.second == 1) {
				answer[1].push_back(m.first);
			}
		}

		set<int> winners;
		for (vector<int> match : matches) {
			if (lose.count(match[0]) == 0) {
				winners.insert(match[0]);
			}
		}

		for (int st : winners) {
			answer[0].push_back(st);
		}

		sort(answer[0].begin(), answer[0].end());
		sort(answer[1].begin(), answer[1].end());

		return answer;
	}
};