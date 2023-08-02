import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

class Solution {
    public List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
        List<List<Integer>> answer = new ArrayList<>();

        Map<Integer, Integer> map = new TreeMap<>();

        for (int[] item : items1) {
            map.put(item[0], map.getOrDefault(item[0], 0) + item[1]);
        }

        for (int[] item : items2) {
            map.put(item[0], map.getOrDefault(item[0], 0) + item[1]);
        }

        for (int key : map.keySet()) {
            List<Integer> temp = new ArrayList<>();

            temp.add(key);
            temp.add(map.get(key));

            answer.add(temp);
        }

        return answer;
    }
}