class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& score) {
		vector<string> answer;

		vector<pair<int, int>> v;
		for (int i = 0; i < score.size(); i++) {
			v.push_back({ score[i], i });
		}

		sort(v.begin(), v.end(), greater<>());

		vector<pair<int, string>> temp;
		for (int i = 0; i < v.size(); i++) {
			if (i == 0) {
				temp.push_back({ v[i].second, "Gold Medal" });
			}
			else if (i == 1) {
				temp.push_back({ v[i].second, "Silver Medal" });
			}
			else if (i == 2) {
				temp.push_back({ v[i].second, "Bronze Medal" });
			}
			else {
				temp.push_back({ v[i].second, to_string(i + 1) });
			}
		}

		sort(temp.begin(), temp.end());

		for (pair<int, string> t : temp) {
			answer.push_back(t.second);
		}

		return answer;
	}
};