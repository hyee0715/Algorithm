class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
		int left = 0, right = image[0].size() - 1;

		while (left < right) {
			for (int i = 0; i < image.size(); i++) {
				int temp = image[i][left];
				image[i][left] = image[i][right];
				image[i][right] = temp;
			}

			left++;
			right--;
		}

		for (int i = 0; i < image.size(); i++) {
			for (int j = 0; j < image[i].size(); j++) {
				if (image[i][j] == 1) {
					image[i][j] = 0;
				}
				else {
					image[i][j] = 1;
				}
			}
		}

		return image;
	}
};