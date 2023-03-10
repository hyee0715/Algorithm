class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int answer = 1;

        int cnt = 1;
        int minNum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (minNum < nums[i]) {
                cnt++;
                answer = Math.max(answer, cnt);
                minNum = nums[i];
            } else {
                cnt = 1;
                minNum = nums[i];
            }
        }

        return answer;
    }
}