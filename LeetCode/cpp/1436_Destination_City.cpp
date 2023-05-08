class Solution {
public:
	string destCity(vector<vector<string>>& paths) {
		string answer;
		unordered_map<string, vector<string>> um;

		for (vector<string> path : paths) {
			um[path[0]].push_back(path[1]);
		}

		for (vector<string> path : paths) {
			if (um.count(path[1]) == 0) {
				answer = path[1];
			}
		}

		return answer;
	}
};