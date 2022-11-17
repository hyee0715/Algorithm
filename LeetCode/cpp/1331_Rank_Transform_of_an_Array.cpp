class Solution {
public:
	vector<int> arrayRankTransform(vector<int>& arr) {
		vector<int> answer, copy_arr;
		unordered_map<int, int> um;

		for (int n : arr) {
			copy_arr.push_back(n);
		}

		sort(copy_arr.begin(), copy_arr.end());

		int rank = 1;

		for (int n : copy_arr) {
			if (um[n] != 0) {
				continue;
			}

			if (um[n] == 0) {
				um[n] = rank;
				rank++;
			}
		}

		for (int i = 0; i < arr.size(); i++) {
			answer.push_back(um[arr[i]]);
		}

		return answer;
	}
};