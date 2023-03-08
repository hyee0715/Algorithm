import java.util.*;

class Solution {
    public String[] solution(String[] strings, int n) {
        String[] answer = {};

        Arrays.sort(strings, (x, y) -> {
            if (x.charAt(n) < y.charAt(n)) {
                return -1;
            }

            if (x.charAt(n) == y.charAt(n)) {
                return x.compareTo(y);
            }

            return 1;
        });

        answer = strings;

        return answer;
    }
}