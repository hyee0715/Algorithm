import java.util.HashMap;
import java.util.Map;

class Solution {
    public long countBadPairs(int[] nums) {
        long answer = 0;
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i] - i, map.getOrDefault(nums[i] - i, 0) + 1);
            answer += i + 1 - map.get(nums[i] - i);
        }

        return answer;
    }
}