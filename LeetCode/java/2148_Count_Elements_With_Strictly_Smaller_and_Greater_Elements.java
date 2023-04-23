import java.util.Map;
import java.util.TreeMap;

class Solution {
    public int countElements(int[] nums) {
        int answer = 0;

        Map<Integer, Integer> map = new TreeMap<>();

        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }

        int idx = 0;

        for (int key : map.keySet()) {
            if (idx != 0 && idx != map.size() - 1) {
                answer += map.get(key);
            }

            idx++;
        }

        return answer;
    }
}