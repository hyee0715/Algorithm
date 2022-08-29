class Solution {
public:
	string firstPalindrome(vector<string>& words) {
		string answer;
		bool found;

		for (int i = 0; i < words.size(); i++) {
			int left = 0;
			int right = words[i].size() - 1;
			found = true;

			while (left <= right) {
				if (words[i][left] != words[i][right]) {
					found = false;
					break;
				}

				left++;
				right--;
			}

			if (found) {
				answer = words[i];
				break;
			}
		}

		return answer;
	}
};