import java.util.*;

class Solution {
    public int solution(int[] topping) {
        int answer = 0;

        Map<Integer, Integer> map1 = new HashMap<>();
        Map<Integer, Integer> map2 = new HashMap<>();

        for (int n : topping) {
            map2.put(n, map2.getOrDefault(n, 0) + 1);
        }

        for (int n : topping) {
            map1.put(n, map1.getOrDefault(n, 0) + 1);
            map2.put(n, map2.get(n) - 1);

            if (map2.get(n) == 0) {
                map2.remove(n);
            }

            if (map1.size() == map2.size()) {
                answer++;
            }
        }

        return answer;
    }
}