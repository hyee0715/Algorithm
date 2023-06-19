import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findCenter(int[][] edges) {
        int answer = 0;
        Map<Integer, Integer> map = new HashMap<>();

        for (int[] edge : edges) {
            map.put(edge[0], map.getOrDefault(edge[0], 0) + 1);
            map.put(edge[1], map.getOrDefault(edge[1], 0) + 1);
        }

        for (int key : map.keySet()) {
            if (map.get(key) == edges.length) {
                answer = key;
            }
        }

        return answer;
    }
}