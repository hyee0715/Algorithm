import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        int[] answer = new int[k];

        Map<Integer, Set<Integer>> map = new HashMap<>();

        for (int[] log : logs) {
            if (!map.containsKey(log[0])) {
                map.put(log[0], new HashSet<Integer>());
            }

            map.get(log[0]).add(log[1]);
        }

        Map<Integer, Integer> record = new HashMap<>();

        for (int key : map.keySet()) {
            answer[map.get(key).size() - 1]++;
        }

        return answer;
    }
}