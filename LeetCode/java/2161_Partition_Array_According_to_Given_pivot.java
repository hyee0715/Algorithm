import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int[] answer = new int[nums.length];

        List<Integer> sm = new ArrayList<>();
        List<Integer> sa = new ArrayList<>();
        List<Integer> lg = new ArrayList<>();

        for (int num : nums) {
            if (num == pivot) {
                sa.add(num);
            } else if (num < pivot) {
                sm.add(num);
            } else {
                lg.add(num);
            }
        }

        int idx = 0;
        for (int n : sm) {
            answer[idx++] = n;
        }

        for (int n : sa) {
            answer[idx++] = n;
        }

        for (int n : lg) {
            answer[idx++] = n;
        }

        return answer;
    }
}