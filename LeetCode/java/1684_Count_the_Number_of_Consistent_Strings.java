import java.util.HashSet;
import java.util.Set;

class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int answer = 0;

        Set<Character> set = new HashSet<>();

        for (int i = 0; i < allowed.length(); i++) {
            set.add(allowed.charAt(i));
        }

        for (String word : words) {
            boolean flag = false;

            for (int i = 0; i < word.length(); i++) {
                if (!set.contains(word.charAt(i))) {
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                answer++;
            }
        }

        return answer;
    }
}