import java.util.HashMap;
import java.util.Map;

class Solution {
    public int rearrangeCharacters(String s, String target) {
        int answer = 100;
        Map<Character, Integer> map = new HashMap<>();
        Map<Character, Integer> map2 = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }

        for (int i = 0; i < target.length(); i++) {
            map2.put(target.charAt(i), map2.getOrDefault(target.charAt(i), 0) + 1);
        }

        for (char key : map2.keySet()) {
            answer = Math.min(answer, map.getOrDefault(key, 0) / map2.get(key));
        }

        return answer;
    }
}