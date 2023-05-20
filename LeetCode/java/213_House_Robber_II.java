class Solution {
    public int rob(int[] nums) {
        int answer = -1;

        if (nums.length <= 2) {
            for (int i = 0; i < nums.length; i++) {
                answer = Math.max(answer, nums[i]);
            }

            return answer;
        }

        int[] dp1 = new int[nums.length];
        int[] dp2 = new int[nums.length];

        dp1[0] = nums[0];
        dp1[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length - 1; i++) {
            dp1[i] = Math.max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }

        dp2[1] = nums[1];
        dp2[2] = Math.max(nums[1], nums[2]);
        for (int i = 3; i < nums.length; i++) {
            dp2[i] = Math.max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }

        answer = Math.max(dp1[nums.length - 2], dp2[nums.length - 1]);
        return answer;
    }
}