class Solution {
    public int arraySign(int[] nums) {
        int negativeCnt = 0;

        for (int n : nums) {
            if (n < 0) {
                negativeCnt++;
            }

            if (n == 0) {
                return 0;
            }
        }

        if (negativeCnt % 2 != 0) {
            return -1;
        }

        return 1;
    }
}