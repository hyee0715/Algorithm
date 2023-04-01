class Solution {
    private int check(String s, String t, int p1, int p2, Integer[][] memo) {
        if (p2 == t.length()) {
            return 1;
        }

        if (p1 == s.length()) {
            return 0;
        }

        if (memo[p1][p2] != null) {
            return memo[p1][p2];
        }

        if (s.charAt(p1) == t.charAt(p2)) {
            memo[p1][p2] = check(s, t, p1 + 1, p2 +  1, memo) + check(s, t, p1 + 1, p2, memo);
        } else {
            memo[p1][p2] = check(s, t, p1 + 1, p2, memo);
        }

        return memo[p1][p2];
    }

    public int numDistinct(String s, String t) {
        Integer[][] memo = new Integer[s.length()][t.length()];

        return check(s, t, 0, 0, memo);
    }
}