class Solution {
    public String longestPalindrome(String s) {
        boolean[][] dp = new boolean[s.length()][s.length()];
        int maxLength = -1;
        String answer = "";

        for (int j = 0; j < s.length(); j++) {
            for (int i = 0; i <= j; i++) {
                if (j - i < 2) {
                    if (s.charAt(i) == s.charAt(j)) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                } else {
                    if (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1] == true) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                }

                if (dp[i][j] == true && maxLength < j - i + 1) {
                    maxLength = j - i + 1;
                    answer = s.substring(i, j + 1);
                }
            }
        }

        return answer;
    }
}