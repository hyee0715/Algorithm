class Solution {
    public int sumOfSquares(int[] nums) {
        int answer = 0;
        int num = nums.length;

        for (int i = 1; i <= nums.length; i++) {
            if (num % i == 0) {
                answer += nums[i - 1] * nums[i - 1];
            }
        }

        return answer;
    }
}