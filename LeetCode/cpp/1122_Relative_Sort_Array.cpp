class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		map<int, int> mp;
		vector<int> answer;

		for (int i = 0; i < arr1.size(); i++) {
			mp[arr1[i]]++;
		}

		for (int i = 0; i < arr2.size(); i++) {
			while (mp[arr2[i]] != 0) {
				answer.push_back(arr2[i]);
				mp[arr2[i]]--;
			}
		}

		for (auto m : mp) {
			if (m.second != 0) {
				while (mp[m.first] != 0) {
					3
						answer.push_back(m.first);
					mp[m.first]--;
				}
			}
		}

		return answer;
	}
};