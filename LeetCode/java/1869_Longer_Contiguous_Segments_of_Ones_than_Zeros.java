class Solution {
    private int findLongestLength(String s, char c) {
        int cnt = 1;
        int maxNum = 0;

        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1) && s.charAt(i) == c) {
                cnt++;
                maxNum = Math.max(maxNum, cnt);
            } else {
                cnt = 1;
            }
        }

        return maxNum;
    }

    public boolean checkZeroOnes(String s) {
        if (s.length() == 1) {
            if (s.charAt(0) == '1') {
                return true;
            }
        }

        int oneLongestLength = findLongestLength(s, '1');
        int zeroLongestLength = findLongestLength(s, '0');

        if (oneLongestLength > zeroLongestLength) {
            return true;
        }

        return false;
    }
}