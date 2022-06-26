class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, int> um1, um2;
		vector<string> answer;
		int min_num = 3000;

		for (int i = 0; i < list1.size(); i++) {
			um1[list1[i]]++;
			um2[list1[i]] += i;
		}

		for (int i = 0; i < list2.size(); i++) {
			um1[list2[i]]++;
			um2[list2[i]] += i;
		}

		for (auto pair : um1) {
			if (pair.second == 2) {
				if (um2[pair.first] < min_num) {
					min_num = um2[pair.first];
					answer.clear();
					answer.push_back(pair.first);
				}
				else if (um2[pair.first] == min_num) {
					answer.push_back(pair.first);
				}
			}
		}

		return answer;
	}
};