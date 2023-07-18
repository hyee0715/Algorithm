import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean digitCount(String num) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < num.length(); i++) {
            map.put(num.charAt(i) - '0', map.getOrDefault(num.charAt(i) - '0', 0) + 1);
        }

        for (int i = 0; i < num.length(); i++) {
            if (map.getOrDefault(i, 0) != num.charAt(i) - '0') {
                return false;
            }
        }

        return true;
    }
}