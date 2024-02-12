class Solution {
public:
	vector<int> parent;

	void unionSimilarPairs(vector<vector<string>>& similarPairs, unordered_map<string, int>& mp) {
		for (vector<string> pairs : similarPairs) {
			string a = pairs[0];
			string b = pairs[1];

			int aIdx = mp[a];
			int bIdx = mp[b];

			if (!sameParent(aIdx, bIdx)) {
				unionParent(aIdx, bIdx);
			}
		}
	}

	void settingMap(unordered_set<string>& st, unordered_map<string, int>& mp) {
		int idx = 0;

		for (string word : st) {
			mp[word] = idx++;
		}
	}

	void initializeParentArray() {
		for (int i = 0; i < parent.size(); i++) {
			parent[i] = i;
		}
	}

	void settingSet(unordered_set<string>& st, vector<vector<string>>& similarPairs) {
		for (vector<string> pairs : similarPairs) {
			st.insert(pairs[0]);
			st.insert(pairs[1]);
		}
	}

	void settingSet(unordered_set<string>& st, vector<string>& sentence) {
		for (string s : sentence) {
			st.insert(s);
		}
	}

	int findParent(int x) {
		if (parent[x] == x) {
			return x;
		}

		return findParent(parent[x]);
	}

	bool sameParent(int x, int y) {
		x = findParent(x);
		y = findParent(y);

		if (x == y) {
			return true;
		}

		return false;
	}

	void unionParent(int x, int y) {
		x = findParent(x);
		y = findParent(y);

		if (x < y) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
		}
	}

	bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
		if (sentence1.size() != sentence2.size()) {
			return false;
		}

		unordered_set<string> st;
		unordered_map<string, int> mp; //단어, parent인덱스

		settingSet(st, similarPairs);
		settingSet(st, sentence1);
		settingSet(st, sentence2);

		parent.assign(st.size(), 0);
		initializeParentArray();

		settingMap(st, mp);

		unionSimilarPairs(similarPairs, mp);

		for (int i = 0; i < sentence1.size(); i++) {
			if (mp.count(sentence1[i]) == 0 || mp.count(sentence2[i]) == 0) {
				return false;
			}

			int sen1Idx = mp[sentence1[i]];
			int sen2Idx = mp[sentence2[i]];

			if (!sameParent(sen1Idx, sen2Idx)) {
				return false;
			}
		}

		return true;
	}
};