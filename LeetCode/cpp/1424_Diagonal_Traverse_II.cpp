class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
		vector<int> answer;
		queue<pair<int, int>> q;

		int dx[] = { 1, 0 };
		int dy[] = { 0, 1 };

		q.push({ 0, 0 });
		answer.push_back(nums[0][0]);

		nums[0][0] = -1;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 2; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= nums.size() || ny >= nums[nx].size()) {
					continue;
				}

				if (nums[nx][ny] != -1) {
					q.push({ nx, ny });
					answer.push_back(nums[nx][ny]);
					nums[nx][ny] = -1;
				}
			}
		}

		return answer;
	}
};