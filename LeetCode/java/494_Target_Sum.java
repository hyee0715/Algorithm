class Solution {
    private int check(int[] nums, int target, int idx, int sum, Integer[][] memo) {
        if (idx == nums.length) {
            if (sum == target) {
                return 1;
            }
            return 0;
        }

        if (memo[idx][sum + 1000] != null) {
            return memo[idx][sum + 1000];
        }

        memo[idx][sum + 1000] = check(nums, target, idx + 1, sum - nums[idx], memo);

        memo[idx][sum + 1000] += check(nums, target, idx + 1, sum + nums[idx], memo);

        return memo[idx][sum + 1000];
    }

    public int findTargetSumWays(int[] nums, int target) {
        Integer[][] memo = new Integer[nums.length][2001];

        return check(nums, target, 0, 0, memo);
    }
}