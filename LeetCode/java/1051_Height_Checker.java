import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int heightChecker(int[] heights) {
        int answer = 0;
        List<Integer> expected = new ArrayList<>();

        for (int n : heights) {
            expected.add(n);
        }

        Collections.sort(expected);

        for (int i = 0; i < heights.length; i++) {
            if (heights[i] != expected.get(i)) {
                answer++;
            }
        }

        return answer;
    }
}