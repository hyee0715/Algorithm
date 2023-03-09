class Solution {
    public int[] solution(int n, int s) {
        int[] answer = {};

        if (s < n) {
            answer = new int[1];
            answer[0] = -1;

            return answer;
        }

        answer = new int[n];

        if (s == n) {
            for (int i = 0; i < n; i++) {
                answer[i] = 1;
            }

            return answer;
        }

        int cnt = s / n;

        for (int i = 0; i < n; i++) {
            answer[i] = cnt;
        }

        if (s % n != 0) {
            int plus = s % n;

            int idx = answer.length - 1;

            while (plus > 0) {
                answer[idx]++;

                idx--;
                plus--;
            }
        }

        return answer;
    }
}