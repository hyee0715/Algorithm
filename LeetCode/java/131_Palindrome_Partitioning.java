import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    List<List<String>> answer = new ArrayList<>();

    private boolean isPalindrome(String s) {
        StringBuilder rev = new StringBuilder(s);
        rev.reverse();

        if (rev.toString().equals(s)) {
            return true;
        }

        return false;
    }

    private void check(String s, int start, int[][] dp, List<String> list) {
        if (start == s.length()) {
            List<String> list2 = new ArrayList<>();

            for (String st : list) {
                list2.add(st);
            }

            answer.add(list2);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (dp[start][end] == -1) {
                if (isPalindrome(s.substring(start, end + 1))) {
                    dp[start][end] = 1;
                } else {
                    dp[start][end] = 0;
                }
            }

            if (dp[start][end] == 1) {
                list.add(s.substring(start, end + 1));

                check(s, end + 1, dp, list);
                list.remove(list.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        int[][] dp = new int[s.length()][s.length()];
        List<String> list = new ArrayList<>();

        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }

        check(s, 0, dp, list);

        return answer;
    }
}