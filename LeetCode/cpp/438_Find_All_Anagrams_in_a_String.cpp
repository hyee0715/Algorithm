class Solution {
public:
	bool check(map<char, int> mp, map<char, int> mp_p) {
		for (auto m : mp) {
			if (m.second != mp_p[m.first])
				return false;
		}
		return true;
	}

	vector<int> findAnagrams(string s, string p) {
		vector<int> answer;
		map<char, int> mp, mp_p;

		if (s.size() < p.size()) {
			return answer;
		}

		for (int i = 0; i < p.size(); i++) {
			mp[s[i]]++;

			mp_p[p[i]]++;
		}

		if (check(mp, mp_p)) {
			answer.push_back(0);
		}

		mp.clear();

		for (int i = 0; i < p.size(); i++) {
			mp[s[i]]++;
		}

		int left = 0;
		int right = p.size() - 1;

		while (right < s.size()) {
			mp[s[left]]--;
			left++;
			right++;
			mp[s[right]]++;

			if (check(mp, mp_p)) {
				answer.push_back(left);
			}
		}

		return answer;
	}
};