import java.util.HashMap;
import java.util.Map;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() <= 1) {
            return s.length();
        }

        int answer = 0;
        Map<Character, Integer> map = new HashMap<>();

        int left = 0;
        int right = 0;

        map.put(s.charAt(left), map.getOrDefault(s.charAt(left), 0) + 1);

        while (left <= right && right < s.length() - 1) {
            right++;

            map.put(s.charAt(right), map.getOrDefault(s.charAt(right), 0) + 1);

            while (map.get(s.charAt(right)) > 1) {
                map.put(s.charAt(left), map.getOrDefault(s.charAt(left), 0) - 1);
                left++;

                answer = Math.max(answer, right - left + 1);
            }

            answer = Math.max(answer, right - left + 1);
        }

        return answer;
    }
}