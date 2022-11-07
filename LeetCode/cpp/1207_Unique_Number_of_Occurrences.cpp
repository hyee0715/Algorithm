class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> um1, um2;

		for (int i = 0; i < arr.size(); i++) {
			um1[arr[i]]++;
		}

		for (auto m : um1) {
			um2[m.second]++;
		}

		for (auto m : um2) {
			if (m.second > 1) {
				return false;
			}
		}

		return true;
	}
};