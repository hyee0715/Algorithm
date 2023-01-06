class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> um;
		map<int, vector<string>, greater<>> mp;
		vector<string> answer;
		bool flag = false;

		for (int i = 0; i < words.size(); i++) {
			um[words[i]]++;
		}

		for (auto m : um) {
			mp[m.second].push_back(m.first);
		}

		for (auto m : mp) {
			for (int i = 0; i < m.second.size(); i++) {
				sort(m.second.begin(), m.second.end());
				answer.push_back(m.second[i]);
				k--;

				if (k == 0) {
					flag = true;
					break;
				}
			}

			if (flag) {
				break;
			}
		}

		return answer;
	}
};