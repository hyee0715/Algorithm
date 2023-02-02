import java.util.Arrays;

class Solution {
    private long findSubarray(long[] dp, int zeroCnt) {
        if (zeroCnt == 1) {
            return 1;
        }

        if (dp[zeroCnt] != -1) {
            return dp[zeroCnt];
        }

        return dp[zeroCnt] = findSubarray(dp, zeroCnt - 1) + zeroCnt;
    }

    public long zeroFilledSubarray(int[] nums) {
        long answer = 0;
        long[] dp = new long[100001];
        Arrays.fill(dp, -1);

        int zeroCnt = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] == nums[i] && nums[i] == 0) {
                zeroCnt++;
                continue;
            }

            if (nums[i - 1] != nums[i] && nums[i - 1] == 0) {
                answer += findSubarray(dp, zeroCnt);
            }

            zeroCnt = 1;
        }

        if (nums[nums.length - 1] == 0) {
            answer += findSubarray(dp, zeroCnt);
        }

        return answer;
    }
}