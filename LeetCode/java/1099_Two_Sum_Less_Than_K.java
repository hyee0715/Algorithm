class Solution {
    public int twoSumLessThanK(int[] nums, int k) {
        int answer = -1;

        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] < k) {
                    answer = Math.max(answer, nums[i] + nums[j]);
                }
            }
        }

        return answer;
    }
}