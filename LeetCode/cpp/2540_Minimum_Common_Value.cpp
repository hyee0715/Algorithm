class Solution {
public:
	int getCommon(vector<int>& nums1, vector<int>& nums2) {
		int answer = -1;
		map<int, int> um;

		um[nums1[0]]++;
		for (int i = 1; i < nums1.size(); i++) {
			if (nums1[i - 1] == nums1[i]) {
				continue;
			}

			um[nums1[i]]++;
		}

		um[nums2[0]]++;
		for (int i = 1; i < nums2.size(); i++) {
			if (nums2[i - 1] == nums2[i]) {
				continue;
			}

			um[nums2[i]]++;
		}

		for (auto m : um) {
			if (m.second > 1) {
				answer = m.first;
				break;
			}
		}

		return answer;
	}
};