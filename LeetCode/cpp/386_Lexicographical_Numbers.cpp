﻿class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<string> v;
		vector<int> answer;

		for (int i = 1; i <= n; i++) {
			string s = to_string(i);
			v.push_back(s);
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			int a = stoi(v[i]);
			answer.push_back(a);
		}

		return answer;
	}
};