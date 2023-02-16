class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		vector<int> cnt, answer;
		vector<pair<int, int>> v;

		for (int i = 0; i < mat.size(); i++) {
			int count = 0;
			for (int j = 0; j < mat[i].size(); j++) {
				if (mat[i][j] == 1) {
					count++;
				}
			}

			cnt.push_back(count);
		}

		for (int i = 0; i < cnt.size(); i++) {
			v.push_back({ cnt[i], i });
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			if (k == 0) {
				break;
			}

			answer.push_back(v[i].second);
			k--;
		}

		return answer;
	}
};