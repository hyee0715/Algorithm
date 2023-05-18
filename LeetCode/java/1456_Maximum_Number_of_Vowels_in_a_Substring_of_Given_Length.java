import java.util.HashSet;
import java.util.Set;

class Solution {
    public int maxVowels(String s, int k) {
        int answer = 0;

        Set<Character> set = new HashSet<>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');

        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (set.contains(s.charAt(i))) {
                cnt++;
            }
        }

        answer = Math.max(answer, cnt);

        int left = 0, right = k - 1;
        while (right < s.length()) {
            if (set.contains(s.charAt(left))) {
                cnt--;
            }

            left++;
            right++;

            if (right == s.length()) {
                break;
            }

            if (set.contains(s.charAt(right))) {
                cnt++;
            }

            answer = Math.max(answer, cnt);
        }

        return answer;
    }
}