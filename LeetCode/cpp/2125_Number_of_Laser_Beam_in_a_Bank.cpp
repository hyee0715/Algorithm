class Solution {
public:
	int numberOfBeams(vector<string>& bank) {
		int answer = 0;
		vector<int> nums;

		for (int i = 0; i < bank.size(); i++) {
			int cnt = 0;

			for (int j = 0; j < bank[i].length(); j++) {
				if (bank[i][j] == '1') {
					cnt++;
				}
			}

			nums.push_back(cnt);
		}

		queue<int> q;
		for (int i = 0; i < nums.size(); i++) {
			q.push(nums[i]);
		}

		int prev = 0;
		while (!q.empty()) {
			if (q.front() != 0) {
				prev = q.front();
				q.pop();
				break;
			}
			else {
				q.pop();
			}
		}

		while (!q.empty()) {
			if (q.front() != 0) {
				answer += (prev * q.front());
				prev = q.front();
				q.pop();
			}
			else {
				q.pop();
			}
		}

		return answer;
	}
};