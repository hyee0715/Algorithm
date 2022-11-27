class Solution {
    public int commonFactors(int a, int b) {
        int answer = 0;
        int min;

        if (a > b) {
            min = b;
        } else {
            min = a;
        }

        for (int i = 1; i <= min; i++) {
            if (a % i == 0 && b % i == 0) {
                answer++;
            }
        }

        return answer;
    }
}