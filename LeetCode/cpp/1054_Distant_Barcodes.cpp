class Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		vector<int> answer(barcodes.size(), 0);
		unordered_map<int, int> um;

		for (int n : barcodes) {
			um[n]++;
		}

		vector<pair<int, int>> v;

		for (auto m : um) {
			v.push_back({ m.second, m.first });
		}

		sort(v.begin(), v.end(), greater<>());

		int idx = 0;

		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].first; j++) {
				answer[idx] = v[i].second;

				if (idx == answer.size() - 2 || idx == answer.size() - 1) {
					idx = 1;
				}
				else {
					idx += 2;
				}
			}
		}

		return answer;
	}
};