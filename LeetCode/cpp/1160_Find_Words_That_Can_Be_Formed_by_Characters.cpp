class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		unordered_map<char, int> um, temp;
		int answer = 0;
		bool flag;

		for (int i = 0; i < chars.size(); i++)
			um[chars[i]]++;

		for (int i = 0; i < words.size(); i++) {
			temp = um;
			flag = false;

			for (int j = 0; j < words[i].size(); j++) {
				temp[words[i][j]]--;

				if (temp[words[i][j]] < 0) {
					flag = true;
					break;
				}
			}

			if (!flag)
				answer += words[i].size();
		}

		return answer;
	}
};