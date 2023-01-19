class Solution {
    public int maxArea(int[] height) {
        int answer = -1;

        int left = 0;
        int right = height.length - 1;

        while (left < right) {
            int minHeight = Math.min(height[left], height[right]);

            int container = (right - left) * minHeight;
            answer = Math.max(answer, container);

            if (height[left] < height[right]) {
                left++;
                continue;
            }

            right--;
        }

        return answer;
    }
}