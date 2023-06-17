class Solution {
public:
	int countConsistentStrings(string allowed, vector<string>& words) {
		int answer = 0;

		set<char> st;

		for (int i = 0; i < allowed.size(); i++) {
			st.insert(allowed[i]);
		}

		for (string word : words) {
			bool flag = false;

			for (int i = 0; i < word.size(); i++) {
				if (st.find(word[i]) == st.end()) {
					flag = true;
					break;
				}
			}

			if (!flag) {
				answer++;
			}
		}

		return answer;
	}
};