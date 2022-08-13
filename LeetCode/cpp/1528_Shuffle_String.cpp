class Solution {
public:
	string restoreString(string s, vector<int>& indices) {
		vector<pair<int, char>> v;
		string answer;

		for (int i = 0; i < indices.size(); i++) {
			v.push_back({ indices[i], s[i] });
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			answer += v[i].second;
		}

		return answer;
	}
};