import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] applyOperations(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                continue;
            }

            nums[i] = nums[i] * 2;
            nums[i + 1] = 0;
        }

        List<Integer> list = new ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }

        int zero_count = 0;
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) == 0) {
                list.remove(i);
                zero_count++;
                i--;
            }
        }

        while (zero_count > 0) {
            list.add(0);
            zero_count--;
        }

        for (int i = 0; i < list.size(); i++) {
            nums[i] = list.get(i);
        }

        return nums;
    }
}