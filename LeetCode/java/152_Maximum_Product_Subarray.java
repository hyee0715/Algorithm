class Solution {
    public int maxProduct(int[] nums) {
        int answer = Integer.MIN_VALUE;
        int max_num = nums[0];
        int min_num = nums[0];

        answer = Math.max(answer, Math.max(max_num, min_num));

        for (int i = 1; i < nums.length; i++) {
            int temp_max_num = max_num;

            max_num = Math.max(nums[i], Math.max(max_num * nums[i], min_num * nums[i]));
            min_num = Math.min(nums[i], Math.min(min_num * nums[i], temp_max_num * nums[i]));

            answer = Math.max(answer, Math.max(max_num, min_num));
        }

        return answer;
    }
}