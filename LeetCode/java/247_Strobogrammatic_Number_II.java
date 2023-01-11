import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
    private List<String> makePairs(int n) {
        char[][] pairs = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

        if (n == 0) {
            return new ArrayList<>(Arrays.asList(""));
        }

        if (n == 1) {
            return new ArrayList<>(Arrays.asList("0", "1", "8"));
        }

        List<String> temp = makePairs(n - 2);
        List<String> answer = new ArrayList<>();

        for (String t : temp) {
            for (int i = 0; i < pairs.length; i++) {
                StringBuilder sb = new StringBuilder();
                sb.append(pairs[i][0]);
                sb.append(t);
                sb.append(pairs[i][1]);

                answer.add(sb.toString());
            }
        }

        return answer;
    }

    public List<String> findStrobogrammatic(int n) {
        List<String> answer = makePairs(n);

        Collections.sort(answer);

        if (n == 1) {
            return answer;
        }

        for (int i = 0; i < answer.size(); i++) {
            if (answer.get(i).charAt(0) == '0') {
                answer.remove(i);
                i--;
            }
        }

        return answer;
    }
}