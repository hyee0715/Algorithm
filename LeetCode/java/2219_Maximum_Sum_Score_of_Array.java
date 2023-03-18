class Solution {
    public long maximumSumScore(int[] nums) {
        long answer = -100001;

        long firstSum = 0;
        long lastSum = 0;

        for (int n : nums) {
            lastSum += n;
        }

        for (int i = 0; i < nums.length; i++) {
            firstSum += nums[i];

            answer = Math.max(answer, Math.max(firstSum, lastSum));

            lastSum -= nums[i];
        }

        return answer;
    }
}