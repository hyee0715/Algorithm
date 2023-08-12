import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> answer = new ArrayList<>();

        Map<Character, Character> map1 = new HashMap<>();
        Map<Character, Character> map2 = new HashMap<>();

        for (String word : words) {
            for (int i = 0; i < word.length(); i++) {
                map1.put(word.charAt(i), pattern.charAt(i));
                map2.put(pattern.charAt(i), word.charAt(i));
            }

            StringBuilder w1 = new StringBuilder();
            StringBuilder w2 = new StringBuilder();

            for (int i = 0; i < word.length(); i++) {
                w1.append(map1.get(word.charAt(i)));
                w2.append(map2.get(pattern.charAt(i)));
            }

            if (w1.toString().equals(pattern) && w2.toString().equals(word)) {
                answer.add(word);
            }
        }

        return answer;
    }
}