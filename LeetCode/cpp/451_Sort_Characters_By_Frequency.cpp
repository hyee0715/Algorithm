class Solution {
public:
	string frequencySort(string s) {
		string answer;
		unordered_map<char, int> um;

		for (int i = 0; i < s.length(); i++) {
			um[s[i]]++;
		}

		vector<pair<int, char>> v;
		for (auto m : um) {
			v.push_back({ m.second, m.first });
		}

		sort(v.begin(), v.end(), greater<>());

		for (int i = 0; i < v.size(); i++) {
			int n = v[i].first;

			for (int j = 0; j < n; j++) {
				answer += v[i].second;
			}
		}

		return answer;
	}
};