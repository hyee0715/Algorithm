import java.util.HashSet;
import java.util.Set;

class Solution {
    public int maximumNumberOfStringPairs(String[] words) {
        int answer = 0;
        Set<String> set = new HashSet<>();

        for (String word : words) {
            set.add(word);
        }

        for (String word : words) {
            StringBuilder rev = new StringBuilder(word);
            rev.reverse();

            if (word.equals(rev.toString())) {
                continue;
            }

            if (set.contains(rev.toString())) {
                answer++;

                set.remove(word);
                set.remove(rev.toString());
            }
        }

        return answer;
    }
}