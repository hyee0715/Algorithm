class Solution {
public:
	int countSubstrings(string s) {
		int answer = 0;

		for (int i = 0; i < s.length(); i++) {
			for (int j = i; j < s.length(); j++) {
				string temp = s.substr(i, (j - i + 1));
				string temp_rev(temp);
				reverse(temp_rev.begin(), temp_rev.end());

				if (temp_rev == temp) {
					answer++;
				}
			}
		}

		return answer;
	}
};