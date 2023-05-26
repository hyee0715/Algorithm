import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int countPairs(int[] nums, int k) {
        int answer = 0;

        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (!map.containsKey(nums[i])) {
                map.put(nums[i], new ArrayList<>());
            }

            map.get(nums[i]).add(i);
        }

        for (Map.Entry<Integer, List<Integer>> m : map.entrySet()) {
            List<Integer> list = m.getValue();

            for (int i = 0; i < list.size() - 1; i++) {
                for (int j = i + 1; j < list.size(); j++) {
                    if (list.get(i) * list.get(j) % k == 0) {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }
}