import java.util.HashMap;
import java.util.Map;

class Solution {
    public int numSplits(String s) {
        int answer = 0;
        Map<Character, Integer> left = new HashMap<>();
        Map<Character, Integer> right = new HashMap<>();

        left.put(s.charAt(0), left.getOrDefault(s.charAt(0), 0) + 1);

        for (int i = 1; i < s.length(); i++) {
            right.put(s.charAt(i), right.getOrDefault(s.charAt(i), 0) + 1);
        }

        if (left.size() == right.size()) {
            answer++;
        }

        for (int i = 1; i < s.length() - 1; i++) {
            right.put(s.charAt(i), right.getOrDefault(s.charAt(i), 0) - 1);
            left.put(s.charAt(i), left.getOrDefault(s.charAt(i), 0) + 1);

            if (right.get(s.charAt(i)) == 0) {
                right.remove(s.charAt(i));
            }

            if (left.size() == right.size()) {
                answer++;
            }
        }

        return answer;
    }
}