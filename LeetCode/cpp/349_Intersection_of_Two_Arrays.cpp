class Solution {
	unordered_map<int, int> um1, um2;
	vector<int> answer;

public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		for (int i = 0; i < nums1.size(); i++) {
			if (um1.find(nums1[i]) == um1.end()) {
				um1[nums1[i]] = 1;
			}
		}

		for (int i = 0; i < nums2.size(); i++) {
			if (um1.find(nums2[i]) != um1.end() && um2.find(nums2[i]) == um2.end()) {
				um2[nums2[i]] = 1;
				answer.push_back(nums2[i]);
			}
		}

		return answer;
	}
};