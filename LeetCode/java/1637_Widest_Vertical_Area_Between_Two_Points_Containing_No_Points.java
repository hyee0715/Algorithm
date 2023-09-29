import java.util.Map;
import java.util.TreeMap;

class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        int answer = 0;
        Map<Integer, Integer> map = new TreeMap<>();

        for (int[] point : points) {
            map.put(point[0], map.getOrDefault(point[0], 0) + 1);
        }

        int prev = -1;

        for (int key : map.keySet()) {
            if (prev == -1) {
                prev = key;
                continue;
            }

            answer = Math.max(answer, key - prev);
            prev = key;
        }

        return answer;
    }
}