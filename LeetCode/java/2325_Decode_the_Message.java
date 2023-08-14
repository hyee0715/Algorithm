import java.util.HashMap;
import java.util.Map;

class Solution {
    public String decodeMessage(String key, String message) {
        StringBuilder answer = new StringBuilder();
        Map<Character, Character> map = new HashMap<>();

        char alphabet = 'a';

        for (int i = 0; i < key.length(); i++) {
            if (key.charAt(i) == ' ' || map.containsKey(key.charAt(i))) {
                continue;
            }

            map.put(key.charAt(i), alphabet++);
        }

        for (int i = 0; i < message.length(); i++) {
            if (message.charAt(i) == ' ') {
                answer.append(' ');
                continue;
            }

            answer.append(map.get(message.charAt(i)));
        }

        return answer.toString();
    }
}