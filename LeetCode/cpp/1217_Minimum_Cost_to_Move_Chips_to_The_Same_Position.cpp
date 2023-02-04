class Solution {
public:
	int minCostToMoveChips(vector<int>& position) {
		if (position.size() == 1) {
			return 0;
		}

		int answer = INT_MAX;
		unordered_map<int, int> cnt_map;

		for (int i = 0; i < position.size(); i++) {
			cnt_map[position[i]]++;
		}

		for (int i = 0; i < position.size(); i++) {
			int move_cnt = 0;

			if (position[i] % 2 == 0) {
				for (pair<int, int> map : cnt_map) {
					if (map.first == position[i]) {
						continue;
					}

					if (map.first % 2 != 0) {
						move_cnt += map.second;
					}
				}

				answer = min(answer, move_cnt);
				continue;
			}

			for (pair<int, int> map : cnt_map) {
				if (map.first == position[i]) {
					continue;
				}

				if (map.first % 2 == 0) {
					move_cnt += map.second;
				}
			}

			answer = min(answer, move_cnt);
		}

		return answer;
	}
};