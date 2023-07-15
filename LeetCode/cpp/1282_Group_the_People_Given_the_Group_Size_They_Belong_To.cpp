class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		vector<vector<int>> answer;
		unordered_map<int, vector<int>> um;

		for (int i = 0; i < groupSizes.size(); i++) {
			um[groupSizes[i]].push_back(i);
		}

		for (auto m : um) {
			int cnt = 0;
			vector<int> v;

			for (int i = 0; i < m.second.size(); i++) {
				v.push_back(m.second[i]);
				cnt++;

				if (cnt == m.first) {
					answer.push_back(v);
					cnt = 0;
					v.clear();
				}
			}
		}

		return answer;
	}
};