import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> answer = new ArrayList<>();

        int start = 0;
        int end = 0;

        while (start <= end && end < s.length()) {
            if (s.charAt(start) == s.charAt(end)) {
                end++;
                continue;
            }

            if (end == s.length()) {
                break;
            }

            if (s.charAt(start) != s.charAt(end)) {
                if (end - start >= 3) {
                    answer.add(Arrays.asList(start, end - 1));
                }

                start = end;
            }
        }

        if (end - start >= 3) {
            answer.add(Arrays.asList(start, end - 1));
        }

        return answer;
    }
}