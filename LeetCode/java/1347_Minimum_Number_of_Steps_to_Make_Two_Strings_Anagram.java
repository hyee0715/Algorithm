import java.util.HashMap;
import java.util.Map;

class Solution {
    public int minSteps(String s, String t) {
        int answer = 0;

        Map<Character, Integer> sMap = new HashMap<>();
        Map<Character, Integer> tMap = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            sMap.put(s.charAt(i), sMap.getOrDefault(s.charAt(i), 0) + 1);
            tMap.put(t.charAt(i), tMap.getOrDefault(t.charAt(i), 0) + 1);
        }

        for (char key : tMap.keySet()) {
            if (sMap.containsKey(key)) {
                if (sMap.get(key) <= tMap.get(key)) {
                    sMap.remove(key);
                } else {
                    sMap.put(key, sMap.get(key) - tMap.get(key));
                }
            }
        }

        for (char key : sMap.keySet()) {
            answer += sMap.get(key);
        }

        return answer;
    }
}