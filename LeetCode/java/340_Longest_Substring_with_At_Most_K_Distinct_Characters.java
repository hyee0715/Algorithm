import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        if (s.length() <= k) {
            return s.length();
        }

        Map<Character, Integer> map = new HashMap<>();
        int answer = -1;

        int left = 0;
        int right = 0;

        while (right < s.length()) {
            map.put(s.charAt(right), right);
            right++;

            if (map.size() > k) {
                int minIdx = Collections.min(map.values());

                map.remove(s.charAt(minIdx));
                left = minIdx + 1;
            }

            answer = Math.max(answer, (right - left));
        }

        return answer;
    }
}