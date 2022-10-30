class Solution {
public:
	static bool compare(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first < b.first;
	}

	vector<int> frequencySort(vector<int>& nums) {
		vector<int> answer;
		unordered_map<int, int> um;
		vector<pair<int, int>> v;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}

		for (auto m : um) {
			v.push_back({ m.second, m.first });
		}

		sort(v.begin(), v.end(), compare);

		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].first; j++) {
				answer.push_back(v[i].second);
			}
		}

		return answer;
	}
};