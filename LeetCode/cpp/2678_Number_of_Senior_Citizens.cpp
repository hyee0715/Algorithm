﻿class Solution {
public:
	int countSeniors(vector<string>& details) {
		int answer = 0;

		for (string detail : details) {
			string age;

			age += detail[11];
			age += detail[12];

			if (stoi(age) > 60) {
				answer++;
			}
		}

		return answer;
	}
};