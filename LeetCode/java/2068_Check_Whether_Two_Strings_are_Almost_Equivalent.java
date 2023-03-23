import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean checkAlmostEquivalent(String word1, String word2) {
        Map<Character, Integer> map1 = new HashMap<>();
        Map<Character, Integer> map2 = new HashMap<>();

        for (char c : word1.toCharArray()) {
            map1.put(c, map1.getOrDefault(c, 0) + 1);
        }

        for (char c : word2.toCharArray()) {
            map2.put(c, map2.getOrDefault(c, 0) + 1);
        }

        for (char key : map1.keySet()) {
            if (Math.abs(map2.getOrDefault(key, 0) - map1.get(key)) > 3) {
                return false;
            }
        }

        for (char key : map2.keySet()) {
            if (Math.abs(map1.getOrDefault(key, 0) - map2.get(key)) > 3) {
                return false;
            }
        }

        return true;
    }
}