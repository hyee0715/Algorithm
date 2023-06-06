import java.util.Arrays;

class Solution {
    int checkTwoSum(int[] nums, int target, int idx) {
        int curAnswer = 0;
        int gap = Integer.MAX_VALUE;

        int left = idx + 1, right = nums.length - 1;

        while (left < right) {
            int tempSum = nums[idx] + nums[left] + nums[right];

            if (Math.abs(target - tempSum) < gap) {
                gap = Math.abs(target - tempSum);
                curAnswer = tempSum;
            }

            if (tempSum > target) {
                right--;
            } else if (tempSum < target) {
                left++;
            } else {
                break;
            }
        }

        return curAnswer;
    }

    public int threeSumClosest(int[] nums, int target) {
        int answer = 0;
        int gap = Integer.MAX_VALUE;

        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; i++) {
            int tempSum = checkTwoSum(nums, target, i);

            if (Math.abs(target - tempSum) < gap) {
                gap = Math.abs(target - tempSum);
                answer = tempSum;
            }
        }

        return answer;
    }
}