import java.util.Arrays;

class Solution {
    public int maximumProduct(int[] nums) {
        int answer = 0;

        Arrays.sort(nums);

        int min1 = nums[0];
        int min2 = nums[1];

        int max1 = nums[nums.length - 1];
        int max2 = nums[nums.length - 2];
        int max3 = nums[nums.length - 3];

        if (min1 < 0 && min2 < 0) {
            answer = Math.max(min1 * min2 * max1, max1 * max2 * max3);
            return answer;
        }

        answer = max1 * max2 * max3;
        return answer;
    }
}