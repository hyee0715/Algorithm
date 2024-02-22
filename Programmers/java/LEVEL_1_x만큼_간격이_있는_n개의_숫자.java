import java.util.*;

class Solution {
    public long[] solution(int x, int n) {
        long[] answer = {};
        List<Long> list = new ArrayList<>();

        long num = x;
        while (n > 0) {
            list.add(num);
            num += x;

            n--;
        }

        answer = new long[list.size()];

        for (int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }

        return answer;
    }
}