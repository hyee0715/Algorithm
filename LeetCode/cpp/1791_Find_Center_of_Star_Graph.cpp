class Solution {
public:
	int findCenter(vector<vector<int>>& edges) {
		int answer = 0;
		unordered_map<int, int> um;

		for (vector<int> edge : edges) {
			um[edge[0]]++;
			um[edge[1]]++;
		}

		for (auto m : um) {
			if (m.second == edges.size()) {
				answer = m.first;
			}
		}

		return answer;
	}
};