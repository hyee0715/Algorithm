import java.util.HashMap;
import java.util.Map;

class Solution {
    public int partitionString(String s) {
        int answer = 0;

        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i)) && map.get(s.charAt(i)) > 0) {
                answer++;
                map.clear();
            }

            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }

        for (char key : map.keySet()) {
            if (map.get(key) > 0) {
                answer++;
                break;
            }
        }

        return answer;
    }
}