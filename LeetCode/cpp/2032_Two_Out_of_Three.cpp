class Solution {
public:
	vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
		vector<int> answer;
		unordered_map<int, int> m1, m2, m3, m4;

		for (int i = 0; i < nums1.size(); i++) {
			m1[nums1[i]]++;
		}

		for (int i = 0; i < nums2.size(); i++) {
			m2[nums2[i]]++;
		}

		for (int i = 0; i < nums3.size(); i++) {
			m3[nums3[i]]++;
		}

		for (auto m : m1) {
			m4[m.first]++;
		}

		for (auto m : m2) {
			m4[m.first]++;
		}

		for (auto m : m3) {
			m4[m.first]++;
		}

		for (auto m : m4) {
			if (m.second >= 2) {
				answer.push_back(m.first);
			}
		}

		return answer;
	}
};