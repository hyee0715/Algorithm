class Solution {
public:
	vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
		vector<int> answer(A.size());

		unordered_map<int, int> um;

		for (int i = 0; i < A.size(); i++) {
			um[A[i]]++;
			um[B[i]]++;

			int cnt = 0;

			for (auto m : um) {
				if (m.second > 1) {
					cnt++;
				}
			}

			answer[i] = cnt;
		}

		return answer;
	}
};