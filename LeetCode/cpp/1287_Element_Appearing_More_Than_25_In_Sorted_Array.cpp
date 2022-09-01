class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		map<int, int> um;
		int answer;
		int max_num = -1;

		for (int i = 0; i < arr.size(); i++) {
			um[arr[i]]++;
		}

		for (auto m : um) {
			if (m.second > max_num) {
				max_num = m.second;
				answer = m.first;
			}
		}

		return answer;
	}
};