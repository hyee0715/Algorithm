import java.util.*;

class Solution {
    public long solution(long n) {
        long answer = 0;
        String s = String.valueOf(n);

        char[] arr = s.toCharArray();

        Arrays.sort(arr);

        StringBuilder sb = new StringBuilder();

        for (char c : arr) {
            sb.append(c);
        }

        sb.reverse();
        answer = Long.parseLong(sb.toString());

        return answer;
    }
}