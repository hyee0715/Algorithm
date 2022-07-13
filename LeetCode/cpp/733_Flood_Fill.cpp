class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		int dx[] = { 0, 0, 1, -1 };
		int dy[] = { 1, -1, 0, 0 };

		queue<pair<int, int>> q;

		int original = image[sr][sc];

		if (original == color)
			return image;

		q.push({ sr, sc });
		image[sr][sc] = color;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= image.size() || ny >= image[0].size()) continue;

				if (image[nx][ny] == original) {
					image[nx][ny] = color;
					q.push({ nx, ny });
				}
			}
		}

		return image;
	}
};