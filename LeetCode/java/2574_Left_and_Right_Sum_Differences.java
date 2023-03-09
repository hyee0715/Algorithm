import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int[] leftRigthDifference(int[] nums) {
        List<Integer> left = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        int[] answer = new int[nums.length];

        left.add(0);
        for (int i = 0; i < nums.length - 1; i++) {
            left.add(left.get(left.size() - 1) + nums[i]);
        }

        right.add(0);
        for (int i = nums.length - 1; i > 0; i--) {
            right.add(right.get(right.size() - 1) + nums[i]);
        }

        Collections.reverse(right);

        for (int i = 0; i < left.size(); i++) {
            answer[i] = Math.abs(left.get(i) - right.get(i));
        }

        return answer;
    }
}