class Solution {
public:
	vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
		vector<int> answer;
		unordered_map<int, vector<int>> um;

		for (int i = 0; i < nums2.size(); i++) {
			um[nums2[i]].push_back(i);
		}

		for (int i = 0; i < nums1.size(); i++) {
			int n = um[nums1[i]][0];
			answer.push_back(n);

			um[nums1[i]].erase(um[nums1[i]].begin());
		}

		return answer;
	}
};