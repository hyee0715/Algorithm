import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    private boolean check(String s, Set<String> set, Boolean[] memo, int start) {
        if (start == s.length()) {
            return true;
        }

        if (memo[start] != null) {
            return memo[start];
        }

        for (int end = start + 1; end <= s.length(); end++) {
            String str = s.substring(start, end);

            if (set.contains(str)) {
                memo[end] = check(s, set, memo, end);

                if (memo[end] == true) {
                    return memo[end];
                }
            }
        }

        return false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> set = new HashSet<>(wordDict);
        Boolean[] memo = new Boolean[s.length() + 1];

        return check(s, set, memo, 0);
    }
}