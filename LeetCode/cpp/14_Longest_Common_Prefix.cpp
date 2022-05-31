class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string answer = "";
		bool flag = true;

		sort(strs.begin(), strs.end());

		int size = strs[0].size();

		for (int i = 0; i < size; i++) {
			int c = strs[0][i]; //faster
			//char c = strs[0][i];

			for (int j = 0; j < strs.size(); j++) {
				if (strs[j][i] != c) {
					flag = false;
					break;
				}
			}

			if (!flag)
				break;

			answer += c;
		}

		return answer;
	}
};