class Solution {
public:
	vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
		vector<vector<int>> answer(score.size(), vector<int>(score[0].size()));

		vector<pair<int, int>> v; //값, 인덱스(행)

		for (int i = 0; i < score.size(); i++) {
			v.push_back({ score[i][k], i });
		}

		sort(v.begin(), v.end(), greater<>());

		int row = 0;

		for (pair<int, int> p : v) {
			for (int i = 0; i < score[0].size(); i++) {
				answer[row][i] = score[p.second][i];
			}

			row++;
		}

		return answer;
	}
};