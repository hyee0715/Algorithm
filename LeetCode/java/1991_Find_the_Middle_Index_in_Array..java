class Solution {
    public int findMiddleIndex(int[] nums) {
        int answer = -1;

        int right = 0;
        for (int i = 1; i < nums.length; i++) {
            right += nums[i];
        }

        int left = 0;
        int idx = 0;
        while (idx < nums.length) {
            if (left == right) {
                answer = idx;
                break;
            }

            left += nums[idx];
            idx++;

            if (idx == nums.length) {
                break;
            }

            right -= nums[idx];
        }

        return answer;
    }
}