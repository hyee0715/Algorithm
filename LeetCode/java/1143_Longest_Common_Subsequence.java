class Solution {
    private int check(String text1, String text2, int p1, int p2, Integer[][] memo) {
        if (p1 == text1.length() || p2 == text2.length()) {
            return 0;
        }

        if (memo[p1][p2] != null) {
            return memo[p1][p2];
        }

        if (text1.charAt(p1) == text2.charAt(p2)) {
            return memo[p1][p2] = check(text1, text2, p1 + 1, p2 + 1, memo) + 1;
        } else {
            return memo[p1][p2] = Math.max(check(text1, text2, p1 + 1, p2, memo), check(text1, text2, p1, p2 + 1, memo));
        }
    }

    public int longestCommonSubsequence(String text1, String text2) {
        Integer[][] memo = new Integer[text1.length()][text2.length()];

        return check(text1, text2, 0, 0, memo);
    }
}