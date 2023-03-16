class Solution {
public:
	vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
		vector<int> answer;
		vector<int> cnt(length + 1, 0);

		for (int i = 0; i < updates.size(); i++) {
			int start = updates[i][0];
			int end = updates[i][1];
			int num = updates[i][2];

			cnt[start] += num;
			cnt[end + 1] += (num * -1);
		}

		answer.push_back(cnt[0]);
		for (int i = 1; i < cnt.size(); i++) {
			answer.push_back(answer[i - 1] + cnt[i]);
		}

		answer.pop_back();

		return answer;
	}
};