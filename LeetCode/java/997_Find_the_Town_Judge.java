import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public int findJudge(int n, int[][] trust) {
        if (trust.length == 0) {
            if (n == 1) {
                return 1;
            }
            return -1;
        }

        int answer = -1;
        Map<Integer, Set<Integer>> map = new HashMap<>();

        for (int[] t : trust) {
            if (!map.containsKey(t[0])) {
                map.put(t[0], new HashSet<>());
            }

            map.get(t[0]).add(t[1]);
        }

        for (int i = 1; i <= n; i++) {
            if (!map.containsKey(i)) {
                for (int key : map.keySet()) {
                    Set<Integer> set = map.get(key);
                    if (!set.contains(i)) {
                        return -1;
                    }
                }

                answer = i;
            }
        }

        return answer;
    }
}