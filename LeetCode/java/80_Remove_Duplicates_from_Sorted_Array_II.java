import java.util.Arrays;

class Solution {
    public int removeDuplicates(int[] nums) {
        int num = nums[0];
        int cnt = 1;
        int minusCnt = 0;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == num) {
                cnt++;

                if (cnt > 2) {
                    nums[i] = 10001;
                    minusCnt++;
                }
                continue;
            }

            cnt = 1;
            num = nums[i];
        }

        Arrays.sort(nums);

        return nums.length - minusCnt;
    }
}