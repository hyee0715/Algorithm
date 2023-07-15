import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> answer = new ArrayList<>();
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < groupSizes.length; i++) {
            if (!map.containsKey(groupSizes[i])) {
                map.put(groupSizes[i], new ArrayList<>());
            }

            map.get(groupSizes[i]).add(i);
        }

        for (int key : map.keySet()) {
            int cnt = 0;
            List<Integer> list = new ArrayList<>();

            for (int i = 0; i < map.get(key).size(); i++) {
                list.add(map.get(key).get(i));
                cnt++;

                if (cnt == key) {
                    answer.add(new ArrayList<>(list));
                    cnt = 0;
                    list.clear();
                }
            }
        }

        return answer;
    }
}