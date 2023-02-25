class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int[] sum = new int[nums.length];
        int answer = Integer.MAX_VALUE;

        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }

        for (int i = 0; i < sum.length; i++) {
            if (sum[i] >= target) {
                answer = Math.min(answer, i + 1);
                break;
            }
        }

        if (answer == Integer.MAX_VALUE) {
            return 0;
        }

        int left = 0, right = 1;

        while (right < sum.length && left < sum.length - 1) {
            int cal = sum[right] - sum[left];

            if (cal >= target) {
                answer = Math.min(answer, right - left);
                left++;
            } else {
                right++;
            }
        }

        return answer;
    }
}