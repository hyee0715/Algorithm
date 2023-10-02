class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] answer = new int[nums.length];

        int[] left = new int[nums.length];
        int[] right = new int[nums.length];

        left[0] = nums[0];

        for (int i = 1; i < nums.length; i++) {
            left[i] = left[i - 1] * nums[i];
        }

        right[nums.length - 1] = nums[nums.length - 1];

        for (int i = nums.length - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i];
        }

        for (int i = 0; i < answer.length; i++) {
            int leftNum = 1;
            int rightNum = 1;

            if (i == 0) {
                rightNum = right[i + 1];
            } else if (i == answer.length - 1) {
                leftNum = left[i - 1];
            } else {
                rightNum = right[i + 1];
                leftNum = left[i - 1];
            }

            answer[i] = leftNum * rightNum;
        }

        return answer;
    }
}