class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> um1, um2;
		vector<int> answer;

		for (int i = 0; i < nums1.size(); i++) {
			um1[nums1[i]]++;
		}

		for (int i = 0; i < nums2.size(); i++) {
			um2[nums2[i]]++;
		}

		for (auto m1 : um1) {
			for (auto m2 : um2) {
				if (m1.first == m2.first) {
					if (m1.second < m2.second) {
						for (int i = 0; i < m1.second; i++) {
							answer.push_back(m1.first);
						}
					}
					else {
						for (int i = 0; i < m2.second; i++) {
							answer.push_back(m2.first);
						}
					}
				}
			}
		}

		return answer;
	}
};