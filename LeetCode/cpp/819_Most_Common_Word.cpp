class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		string s;
		unordered_map<string, int> um;
		vector<pair<int, string>> words;
		set<string> st;
		string answer;

		for (string ban : banned) {
			st.insert(ban);
		}

		for (int i = 0; i < paragraph.size(); i++) {
			if (!(paragraph[i] >= 'a' && paragraph[i] <= 'z') && !(paragraph[i] >= 'A' && paragraph[i] <= 'Z')) {
				paragraph[i] = ' ';
			}
		}

		for (int i = 0; i < paragraph.size() - 1; i++) {
			if (paragraph[i] == ' ' && paragraph[i + 1] == ' ') {
				paragraph.erase(paragraph.begin() + i, paragraph.begin() + (i + 1));
			}
		}

		for (int i = 0; i < paragraph.size(); i++) {
			if (paragraph[i] == ' ') {
				for (int j = 0; j < s.size(); j++) {
					s[j] = tolower(s[j]);
				}

				um[s]++;
				s.clear();
				continue;
			}

			s += paragraph[i];
		}

		if (!s.empty()) {
			for (int j = 0; j < s.size(); j++) {
				s[j] = tolower(s[j]);
			}

			um[s]++;
			s.clear();
		}

		for (auto m : um) {
			words.push_back({ m.second, m.first });
		}

		sort(words.begin(), words.end(), greater<>());

		for (int i = 0; i < words.size(); i++) {
			if (st.find(words[i].second) == st.end()) {
				answer = words[i].second;
				break;
			}
		}

		return answer;
	}
};