class Solution {
public:
	int secondHighest(string s) {
		unordered_map<int, int> um;
		vector<int> v;

		for (int i = 0; i < s.size(); i++) {
			if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9)
				um[s[i] - '0']++;
		}

		for (auto m : um) {
			v.push_back(m.first);
		}

		if (v.size() < 2) {
			return -1;
		}

		sort(v.begin(), v.end(), greater<>());

		return v[1];
	}
};