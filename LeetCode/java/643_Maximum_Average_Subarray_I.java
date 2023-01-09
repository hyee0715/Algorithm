class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double answer = Integer.MIN_VALUE;

        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        answer = Math.max(answer, sum / k);

        int left = 0;
        int right = k - 1;

        while (left <= right && right < nums.length - 1) {
            sum -= nums[left];
            left++;
            right++;
            sum += nums[right];

            answer = Math.max(answer, sum / k);
        }

        return answer;
    }
}