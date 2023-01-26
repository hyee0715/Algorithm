class Solution {
    public int differenceOfSum(int[] nums) {
        int elementSum = 0, digitSum = 0;

        for (int i = 0; i < nums.length; i++) {
            elementSum += nums[i];

            String s = String.valueOf(nums[i]);
            for (int j = 0; j < s.length(); j++)  {
                digitSum += (s.charAt(j) - '0');
            }
        }

        return Math.abs(elementSum - digitSum);
    }
}