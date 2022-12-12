class Solution {
    public int dominantIndex(int[] nums) {
        int answer = -1;
        int max = -1, max_idx = -1;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > max) {
                max_idx = i;
                max = nums[i];
            }
        }

        for (int i = 0; i < nums.length; i++) {
            if (i == max_idx) {
                continue;
            }

            if (nums[i] * 2 > max) {
                return answer;
            }
        }

        answer = max_idx;
        return answer;
    }
}