class Solution {
public:
	int maximumNumberOfStringPairs(vector<string>& words) {
		int answer = 0;
		set<string> st(words.begin(), words.end());

		for (string word : words) {
			string rev = word;
			reverse(rev.begin(), rev.end());

			if (word == rev) {
				continue;
			}

			if (st.find(rev) != st.end()) {
				answer++;

				st.erase(word);
				st.erase(rev);
			}
		}

		return answer;
	}
};