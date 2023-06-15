import java.util.Arrays;

class Solution {
    public int maxConsecutive(int bottom, int top, int[] special) {
        int answer = 0;

        Arrays.sort(special);

        for (int i = 0; i < special.length - 1; i++) {
            answer = Math.max(answer, special[i + 1] - special[i] - 1);
        }

        answer = Math.max(answer, special[0] - bottom);
        answer = Math.max(answer, top - special[special.length - 1]);

        return answer;
    }
}