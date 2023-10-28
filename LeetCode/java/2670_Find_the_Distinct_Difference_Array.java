import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] distinctDifferenceArray(int[] nums) {
        int[] answer = new int[nums.length];
        int idx = 0;

        Map<Integer, Integer> prefix = new HashMap<>();
        Map<Integer, Integer> suffix = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (j <= i) {
                    prefix.put(nums[j], prefix.getOrDefault(nums[j], 0) + 1);
                } else {
                    suffix.put(nums[j], suffix.getOrDefault(nums[j], 0) + 1);
                }
            }

            answer[idx++] = prefix.size() - suffix.size();

            prefix.clear();
            suffix.clear();
        }

        return answer;
    }
}