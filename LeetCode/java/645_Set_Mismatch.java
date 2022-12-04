import java.util.HashSet;
import java.util.Set;

class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] answer = new int[2];
        Set<Integer> set = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {
            if (!set.contains(nums[i])) {
                set.add(nums[i]);
                continue;
            }

            if (set.contains(nums[i])) {
                answer[0] = nums[i];
            }
        }

        for (int i = 1; i <= nums.length; i++) {
            if (!set.contains(i)) {
                answer[1] = i;
            }
        }

        return answer;
    }
}