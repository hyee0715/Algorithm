import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean makeEqual(String[] words) {
        int wordCount = words.length;
        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                map.put(words[i].charAt(j), map.getOrDefault(words[i].charAt(j), 0) + 1);
            }
        }

        for (Character key : map.keySet()) {
            if (map.get(key) % wordCount != 0) {
                return false;
            }
        }

        return true;
    }
}