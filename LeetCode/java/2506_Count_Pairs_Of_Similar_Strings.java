import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

class Solution {
    public int similarPairs(String[] words) {
        int answer = 0;
        String[] updatedWords = new String[words.length];
        Map<String, Integer> count = new HashMap<>();

        for (int i = 0; i < words.length; i++) {
            Map<Character, Integer> map = new TreeMap<>();

            for (int j = 0; j < words[i].length(); j++) {
                map.put(words[i].charAt(j), map.getOrDefault(words[i].charAt(j), 0) + 1);
            }

            StringBuilder temp = new StringBuilder();
            for (Character key : map.keySet()) {
                temp.append(key);
            }

            updatedWords[i] = temp.toString();
        }

        for (int i = 0; i < updatedWords.length - 1; i++) {
            for (int j = i + 1; j < updatedWords.length; j++) {
                if (updatedWords[i].equals(updatedWords[j])) {
                    answer++;
                }
            }
        }

        return answer;
    }
}