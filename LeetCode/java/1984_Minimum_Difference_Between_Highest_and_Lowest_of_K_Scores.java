import java.util.Arrays;

class Solution {
    public int minimumDifference(int[] nums, int k) {
        if (nums.length == 1) {
            return 0;
        }

        int answer = 100002;

        Arrays.sort(nums);

        int left = 0;
        int right = k - 1;

        while (right < nums.length) {
            answer = Math.min(answer, nums[right] - nums[left]);

            left++;
            right++;
        }

        return answer;
    }
}