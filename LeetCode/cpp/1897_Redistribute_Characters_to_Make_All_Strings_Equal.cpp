class Solution {
public:
	bool makeEqual(vector<string>& words) {
		int word_count = words.size();
		unordered_map<char, int> um;

		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words[i].size(); j++) {
				um[words[i][j]]++;
			}
		}

		for (auto m : um) {
			if (m.second % word_count != 0) {
				return false;
			}
		}

		return true;
	}
};