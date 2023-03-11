import java.util.HashMap;
import java.util.Map;

class Solution {
    private boolean isDuplicate(Map<Character, Integer> map) {
        for (char key : map.keySet()) {
            if (map.get(key) > 1) {
                return true;
            }
        }

        return false;
    }

    public int numKLenSubstrNoRepeats(String s, int k) {
        Map<Character, Integer> map = new HashMap<>();
        int answer = 0;

        if (s.length() < k) {
            return 0;
        }

        for (int i = 0; i < k; i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }

        int left = 0, right = k - 1;

        while (right < s.length()) {
            if (!isDuplicate(map)) {
                answer++;
            }

            map.put(s.charAt(left), map.getOrDefault(s.charAt(left), 0) - 1);
            left++;
            right++;

            if (right == s.length()) {
                break;
            }

            map.put(s.charAt(right), map.getOrDefault(s.charAt(right), 0) + 1);
        }

        return answer;
    }
}