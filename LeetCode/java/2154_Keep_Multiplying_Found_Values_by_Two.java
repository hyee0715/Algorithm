import java.util.HashSet;
import java.util.Set;

class Solution {
    public int findFinalValue(int[] nums, int original) {
        Set<Integer> set = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {
            set.add(nums[i]);
        }

        while (true) {
            if (!set.contains(original)) {
                break;
            }

            original = original * 2;
        }

        return original;
    }
}