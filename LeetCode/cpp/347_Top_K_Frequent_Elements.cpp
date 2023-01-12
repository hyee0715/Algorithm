class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> um;
		vector<pair<int, int>> cnt;
		vector<int> answer;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}

		for (pair<int, int> m : um) {
			cnt.push_back({ m.second, m.first });
		}

		sort(cnt.begin(), cnt.end(), greater<>());

		for (int i = 0; i < k; i++) {
			answer.push_back(cnt[i].second);
		}

		return answer;
	}
};