import java.util.ArrayList;
import java.util.List;

class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        List<Integer> indexes = new ArrayList<>();
        int answer = nums.length;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                indexes.add(i);
            }
        }

        for (int index : indexes) {
            answer = Math.min(answer, Math.abs(index - start));
        }

        return answer;
    }
}