import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer> temp = new ArrayList<>();

        for (int num : nums) {
            String s = String.valueOf(num);

            for (int i = 0; i < s.length(); i++) {
                temp.add(s.charAt(i) - '0');
            }
        }

        int[] answer = new int[temp.size()];

        int idx = 0;
        for (int n : temp) {
            answer[idx++] = n;
        }

        return answer;
    }
}