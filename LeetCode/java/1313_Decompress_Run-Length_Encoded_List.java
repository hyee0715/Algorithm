import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] decompressRLElist(int[] nums) {
        int[] answer;
        List<Integer> tempAnswer = new ArrayList<>();

        for (int i = 0; i < nums.length; i += 2) {
            int freq = nums[i];
            int val = nums[i + 1];

            for (int j = 0; j < freq; j++) {
                tempAnswer.add(val);
            }
        }

        answer = new int[tempAnswer.size()];

        int idx = 0;
        for (int n : tempAnswer) {
            answer[idx++] = n;
        }

        return answer;
    }
}