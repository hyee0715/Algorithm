class Solution {
    public int maximumCount(int[] nums) {
        int pos = 0, neg = 0;

        for (int n : nums) {
            if (n > 0) {
                pos++;
            }
            else if (n < 0) {
                neg++;
            }
        }

        if (pos < neg) {
            return neg;
        }

        return pos;
    }
}