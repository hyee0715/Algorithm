class Solution {
public:
	int similarPairs(vector<string>& words) {
		int answer = 0;
		vector<string> updated_words;
		unordered_map<string, int> count;

		for (int i = 0; i < words.size(); i++) {
			map<char, int> um;

			for (int j = 0; j < words[i].size(); j++) {
				um[words[i][j]]++;
			}

			string temp;
			for (auto m : um) {
				temp += m.first;
			}

			updated_words.push_back(temp);
		}

		for (int i = 0; i < updated_words.size() - 1; i++) {
			for (int j = i + 1; j < updated_words.size(); j++) {
				if (updated_words[i] == updated_words[j]) {
					answer++;
				}
			}
		}

		return answer;
	}
};