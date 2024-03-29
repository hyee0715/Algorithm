import java.util.Arrays;

class Solution {
    public int minPairSum(int[] nums) {
        int answer = 0;

        Arrays.sort(nums);

        for (int i = 0; i < nums.length / 2; i++) {
            answer = Math.max(answer, nums[i] + nums[nums.length - 1 - i]);
        }

        return answer;
    }
}