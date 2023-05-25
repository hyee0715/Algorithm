class Solution {
public:
	vector<vector<int>> highFive(vector<vector<int>>& items) {
		vector<vector<int>> answer;
		unordered_map<int, vector<int>> um;

		for (vector<int> item : items) {
			um[item[0]].push_back(item[1]);
		}

		for (auto m : um) {
			vector<int> v = m.second;

			sort(v.begin(), v.end(), greater<>());

			int sum = 0;
			for (int i = 0; i < 5; i++) {
				sum += v[i];
			}

			int avg = sum / 5;

			answer.push_back({ m.first, avg });
		}

		sort(answer.begin(), answer.end());

		return answer;
	}
};