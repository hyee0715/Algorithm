class Solution {
public:
	int findLonelyPixel(vector<vector<char>>& picture) {
		unordered_map<int, int> row_map, col_map;
		vector<pair<int, int>> b_location;
		int answer = 0;

		for (int i = 0; i < picture.size(); i++) {
			for (int j = 0; j < picture[i].size(); j++) {
				if (picture[i][j] == 'B') {
					row_map[i]++;
					col_map[j]++;

					b_location.push_back({ i, j });
				}
			}
		}

		for (int i = 0; i < b_location.size(); i++) {
			if (row_map[b_location[i].first] <= 1 && col_map[b_location[i].second] <= 1) {
				answer++;
			}
		}

		return answer;
	}
};