import java.util.HashMap;
import java.util.Map;

class Solution {
    public int longestRepeatingSubstring(String s) {
        int answer = 0;
        Map<String, Integer> map = new HashMap<>();

        for (int i = s.length() - 1; i >= 2; i--) {
            map.clear();

            StringBuilder temp = new StringBuilder();

            for (int j = 0; j < i; j++) {
                temp.append(s.charAt(j));
            }

            map.put(temp.toString(), map.getOrDefault(temp.toString(), 0) + 1);

            temp.deleteCharAt(0);

            for (int j = i; j < s.length(); j++) {
                temp.append(s.charAt(j));

                map.put(temp.toString(), map.getOrDefault(temp.toString(), 0) + 1);
                temp.deleteCharAt(0);
            }

            for (Map.Entry<String, Integer> m : map.entrySet()) {
                if (m.getValue() > 1) {
                    if (answer < m.getKey().length()) {
                        answer = m.getKey().length();
                    }
                }
            }

            if (answer > 0) {
                break;
            }
        }

        return answer;
    }
}