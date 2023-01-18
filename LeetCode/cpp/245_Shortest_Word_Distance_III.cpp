class Solution {
public:
	int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
		int answer = 100002;
		unordered_map<string, vector<int>> um;

		for (int i = 0; i < wordsDict.size(); i++) {
			um[wordsDict[i]].push_back(i);
		}

		if (word1 == word2) {
			vector<int> v = um[word1];

			sort(v.begin(), v.end());

			for (int i = 0; i < v.size() - 1; i++) {
				answer = min(answer, v[i + 1] - v[i]);
			}

			return answer;
		}

		vector<int> v1 = um[word1];
		vector<int> v2 = um[word2];

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		int p1 = 0;
		int p2 = 0;

		while (p1 < v1.size() && p2 < v2.size()) {
			answer = min(answer, abs(v1[p1] - v2[p2]));

			if (v1[p1] <= v2[p2]) {
				p1++;
				continue;
			}

			if (v1[p1] > v2[p2]) {
				p2++;
			}
		}

		return answer;
	}
};