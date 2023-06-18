import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public int countPoints(String rings) {
        int answer = 0;
        Map<Integer, Set<Character>> map = new HashMap<>();

        for (int i = 0; i < rings.length(); i += 2) {
            char color = rings.charAt(i);
            int num = rings.charAt(i + 1) - 'A';

            if (!map.containsKey(num)) {
                map.put(num, new HashSet<>());
            }

            map.get(num).add(color);
        }

        for (int key : map.keySet()) {
            if (map.get(key).size() == 3) {
                answer++;
            }
        }

        return answer;
    }
}