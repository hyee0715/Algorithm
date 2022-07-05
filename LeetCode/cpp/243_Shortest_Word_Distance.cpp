class Solution {
public:
	int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
		int idx1 = -1, idx2 = -1;
		int answer = 30001;

		for (int i = 0; i < wordsDict.size(); i++) {
			if (wordsDict[i] == word1)
				idx1 = i;

			if (wordsDict[i] == word2)
				idx2 = i;

			if (idx1 != -1 && idx2 != -1) {
				int distance = abs(idx1 - idx2);
				answer = min(answer, distance);
			}
		}

		return answer;
	}
};