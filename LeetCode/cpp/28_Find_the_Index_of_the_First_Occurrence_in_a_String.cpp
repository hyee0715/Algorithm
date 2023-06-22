class Solution {
public:
	int strStr(string haystack, string needle) {
		int answer = -1;

		int idx = -1;
		for (int i = 0; i < haystack.length(); i++) {
			if (haystack[i] == needle[0]) {
				idx = i;

				bool flag = true;
				for (int j = 0; j < needle.length(); j++) {
					if (i + needle.length() > haystack.length()) {
						flag = false;
						break;
					}

					if (haystack[i + j] != needle[j]) {
						flag = false;
						break;
					}
				}

				if (flag) {
					answer = i;
					break;
				}
			}
		}

		return answer;
	}
};