import java.util.*;

class Solution {
    public int solution(int k, int m, int[] score) {
        int answer = 0;

        Arrays.sort(score);

        int cnt = 1;
        for (int i = score.length - 1; i >= 0; i--) {
            if (cnt == m) {
                answer += (score[i] * m);
                cnt = 1;
            } else {
                cnt++;
            }
        }

        return answer;
    }
}