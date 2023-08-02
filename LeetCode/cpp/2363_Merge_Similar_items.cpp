class Solution {
public:
	vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
		vector<vector<int>> answer;

		map<int, int> mp;

		for (vector<int> item : items1) {
			mp[item[0]] += item[1];
		}

		for (vector<int> item : items2) {
			mp[item[0]] += item[1];
		}

		for (auto m : mp) {
			answer.push_back({ m.first, m.second });
		}

		return answer;
	}
};