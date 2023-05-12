import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxNumberOfBalloons(String text) {
        int answer = Integer.MAX_VALUE;

        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < text.length(); i++) {
            map.put(text.charAt(i), map.getOrDefault(text.charAt(i), 0) + 1);
        }

        char[] alphabet = {'b', 'a', 'l', 'o', 'n'};
        for (char c : alphabet) {
            if (!map.containsKey(c)) {
                return 0;
            }
        }

        for (Map.Entry<Character, Integer> m : map.entrySet()) {
            if (m.getKey() == 'b' || m.getKey() == 'a' || m.getKey() == 'n') {
                answer = Math.min(answer, m.getValue());
                continue;
            }

            if (m.getKey() == 'l' || m.getKey() == 'o') {
                if (m.getValue() < 2) {
                    return 0;
                }

                answer = Math.min(answer, m.getValue() / 2);
            }
        }

        return answer;
    }
}