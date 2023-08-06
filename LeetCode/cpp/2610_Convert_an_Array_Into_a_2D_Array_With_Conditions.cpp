class Solution {
public:
	vector<vector<int>> findMatrix(vector<int>& nums) {
		vector<vector<int>> answer;
		unordered_map<int, int> um;

		for (int n : nums) {
			um[n]++;
		}

		while (!um.empty()) {
			vector<int> v;
			vector<int> rmv;

			for (auto m : um) {
				v.push_back(m.first);

				um[m.first]--;

				if (um[m.first] == 0) {
					rmv.push_back(m.first);
				}
			}

			for (int n : rmv) {
				um.erase(n);
			}

			answer.push_back(v);
		}

		return answer;
	}
};