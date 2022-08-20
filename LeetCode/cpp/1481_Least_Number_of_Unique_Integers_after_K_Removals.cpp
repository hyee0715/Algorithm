class Solution {
public:
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
		vector<pair<int, int>> v;
		unordered_map<int, int> um;
		int answer = 0;

		for (int i = 0; i < arr.size(); i++) {
			um[arr[i]]++;
		}

		for (auto m : um) {
			v.push_back({ m.second, m.first });
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			if (v[i].first > k) {
				v[i].first -= k;
				k = 0;
			}
			else {
				k -= v[i].first;
				v[i].first = 0;
			}
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i].first != 0) {
				answer++;
			}
		}

		return answer;
	}
};