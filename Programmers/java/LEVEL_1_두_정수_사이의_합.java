class Solution {
    public long solution(int a, int b) {
        long answer = 0;

        if (a > b) {
            return solution(b, a);
        }

        if (a == b) {
            answer = a;

            return answer;
        }

        for (int i = a; i <= b; i++) {
            answer += i;
        }

        return answer;
    }
}