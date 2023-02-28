class Solution {
public:
	vector<int> findArray(vector<int>& pref) {
		vector<int> answer(pref.size(), 0);

		answer[0] = pref[0];

		for (int i = 1; i < pref.size(); i++) {
			answer[i] = pref[i] ^ pref[i - 1];
		}

		return answer;
	}
};