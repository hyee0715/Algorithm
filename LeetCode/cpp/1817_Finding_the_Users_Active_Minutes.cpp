class Solution {
public:
	vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
		vector<int> answer(k, 0);

		unordered_map<int, set<int>> um;

		for (vector<int> log : logs) {
			um[log[0]].insert(log[1]);
		}

		unordered_map<int, int> record;

		for (auto m : um) {
			answer[m.second.size() - 1]++;
		}

		return answer;
	}
};