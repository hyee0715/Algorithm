import java.util.HashSet;
import java.util.Set;

class Solution {
    public int countGoodSubstrings(String s) {
        Set<Character> set = new HashSet<>();
        int answer = 0;
        boolean flag;

        if (s.length() < 3) {
            return 0;
        }

        for (int i = 0; i < s.length() - 2; i++) {
            set.clear();
            flag = false;

            for (int j = 0; j < 3; j++) {
                if (set.contains(s.charAt(i + j))) {
                    flag = true;
                } else {
                    set.add(s.charAt(i + j));
                }
            }

            if (!flag) {
                answer++;
            }
        }

        return answer;
    }
}