import java.util.HashMap;
import java.util.Map;

class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        if (s.length() <= 2) {
            return s.length();
        }

        int answer = -1;
        Map<Character, Integer> map = new HashMap<>();

        int left = 0;
        int right = 1;

        map.put(s.charAt(left), map.getOrDefault(s.charAt(left), 0) + 1);
        map.put(s.charAt(right), map.getOrDefault(s.charAt(right), 0) + 1);

        while (right < s.length() - 1) {
            right++;
            map.put(s.charAt(right), map.getOrDefault(s.charAt(right), 0) + 1);

            while (map.size() > 2) {
                map.put(s.charAt(left), map.getOrDefault(s.charAt(left), 0) - 1);

                if (map.get(s.charAt(left)) == 0) {
                    map.remove(s.charAt(left));
                }

                left++;
            }

            int sum = 0;
            for (char key : map.keySet()) {
                sum += map.get(key);
            }

            answer = Math.max(answer, sum);
        }

        return answer;
    }
}