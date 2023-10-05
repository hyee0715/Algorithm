import java.util.Arrays;

class Solution {
    public int maxProductDifference(int[] nums) {
        int answer = 0;

        Arrays.sort(nums);

        answer = (nums[nums.length - 1] * nums[nums.length - 2]) - (nums[0] * nums[1]);

        return answer;
    }
}