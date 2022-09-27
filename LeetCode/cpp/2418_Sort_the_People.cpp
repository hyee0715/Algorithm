class Solution {
public:
	vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
		vector<pair<int, string>> v;
		vector<string> answer;

		for (int i = 0; i < names.size(); i++) {
			v.push_back({ heights[i], names[i] });
		}

		sort(v.begin(), v.end(), greater<>());

		for (int i = 0; i < v.size(); i++) {
			answer.push_back(v[i].second);
		}

		return answer;
	}
};