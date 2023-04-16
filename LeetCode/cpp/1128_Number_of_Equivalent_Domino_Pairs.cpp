class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		int answer = 0;
		for (int i = 0; i < dominoes.size(); i++) {
			sort(dominoes[i].begin(), dominoes[i].end());
		}

		sort(dominoes.begin(), dominoes.end());

		int cnt = 0;
		for (int i = 0; i < dominoes.size() - 1; i++) {
			if (dominoes[i][0] == dominoes[i + 1][0] && dominoes[i][1] == dominoes[i + 1][1]) {
				if (cnt == 0) {
					cnt++;
				}

				cnt++;
			}
			else {
				answer += (cnt * (cnt - 1)) / 2;
				cnt = 0;
			}
		}

		answer += (cnt * (cnt - 1)) / 2;

		return answer;
	}
};