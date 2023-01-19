class Solution {
public:
	int maxArea(vector<int>& height) {
		int answer = -1;

		int left = 0;
		int right = height.size() - 1;

		while (left < right) {
			int min_height = min(height[left], height[right]);

			int container = (right - left) * min_height;
			answer = max(answer, container);

			if (height[left] < height[right]) {
				left++;
				continue;
			}

			right--;
		}

		return answer;
	}
};