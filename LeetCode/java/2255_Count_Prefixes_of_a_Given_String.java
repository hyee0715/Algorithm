import java.util.HashMap;
import java.util.Map;

class Solution {
    public int countPrefixes(String[] words, String s) {
        int answer = 0;

        Map<String, Integer> map = new HashMap<>();

        for (String word : words) {
            map.put(word, map.getOrDefault(word, 0) + 1);
        }

        StringBuilder prefix = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            prefix.append(s.charAt(i));

            if (map.containsKey(prefix.toString())) {
                answer += map.get(prefix.toString());
            }
        }

        return answer;
    }
}