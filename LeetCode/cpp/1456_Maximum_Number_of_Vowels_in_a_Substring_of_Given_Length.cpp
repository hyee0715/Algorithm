class Solution {
public:
	int maxVowels(string s, int k) {
		int answer = 0;

		set<char> st;
		st.insert('a');
		st.insert('e');
		st.insert('i');
		st.insert('o');
		st.insert('u');

		int cnt = 0;
		for (int i = 0; i < k; i++) {
			if (st.find(s[i]) != st.end()) {
				cnt++;
			}
		}

		answer = max(answer, cnt);

		int left = 0, right = k - 1;
		while (right < s.length()) {
			if (st.find(s[left]) != st.end()) {
				cnt--;
			}

			left++;
			right++;

			if (right == s.length()) {
				break;
			}

			if (st.find(s[right]) != st.end()) {
				cnt++;
			}

			answer = max(answer, cnt);
		}

		return answer;
	}
};