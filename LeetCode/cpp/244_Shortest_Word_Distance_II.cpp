class WordDistance {
public:
	unordered_map<string, vector<int>> um;

	WordDistance(vector<string>& wordsDict) {
		for (int i = 0; i < wordsDict.size(); i++) {
			um[wordsDict[i]].push_back(i);
		}
	}

	int shortest(string word1, string word2) {
		vector<int> n1 = um[word1];
		vector<int> n2 = um[word2];

		int answer = 30002;
		for (int i = 0; i < n1.size(); i++) {
			for (int j = 0; j < n2.size(); j++) {
				answer = min(answer, abs(n1[i] - n2[j]));
			}
		}

		return answer;
	}
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */