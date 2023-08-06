import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        List<List<Integer>> answer = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();

        for (int n : nums) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }

        while(!map.isEmpty()) {
            List<Integer> list = new ArrayList<>();
            List<Integer> rmv = new ArrayList<>();

            for (int key : map.keySet()) {
                list.add(key);

                map.put(key, map.get(key) - 1);

                if (map.get(key) == 0) {
                    rmv.add(key);
                }
            }

            for (int n : rmv) {
                map.remove(n);
            }

            answer.add(new ArrayList<>(list));
        }

        return answer;
    }
}