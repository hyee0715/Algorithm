import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public int removeDuplicates(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int answer = 0;

        for (int i = 0; i < nums.length; i++) {
            if (!map.containsKey(nums[i])) {
                map.put(nums[i], 1);
                continue;
            }

            nums[i] = 101;
        }

        Arrays.sort(nums);

        answer = map.size();

        return answer;
    }
}