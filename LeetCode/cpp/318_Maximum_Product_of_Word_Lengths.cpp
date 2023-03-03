class Solution {
public:
	int maxProduct(vector<string>& words) {
		vector<int> nums, wordsLength;
		int answer = -1;

		for (int i = 0; i < words.size(); i++) {
			string s = words[i];

			int n = 0;
			for (int j = 0; j < s.length(); j++) {
				n |= (1 << (s[j] - 'a'));
			}

			nums.push_back(n);

			wordsLength.push_back(words[i].length());
		}

		for (int i = 0; i < nums.size() - 1; i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if ((nums[i] & nums[j]) == 0) {
					answer = max(answer, wordsLength[i] * wordsLength[j]);
				}
			}
		}

		if (answer == -1) {
			answer = 0;
		}

		return answer;
	}
};