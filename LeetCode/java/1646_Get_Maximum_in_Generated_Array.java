class Solution {
    public int getMaximumGenerated(int n) {
        if (n == 0) {
            return 0;
        }

        int answer = -1;
        int[] nums = new int[n + 1];
        nums[0] = 0;
        nums[1] = 1;

        for (int i = 1; 2*i+1 <= n; i++) {
            nums[2 * i] = nums[i];
            nums[2 * i + 1] = (nums[i] + nums[i + 1]);
        }

        for (int a : nums) {
            answer = Math.max(answer, a);
        }

        return answer;
    }
}