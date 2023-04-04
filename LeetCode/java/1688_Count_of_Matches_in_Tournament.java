class Solution {
    public int numberOfMatches(int n) {
        int answer = 0;

        while (n > 1) {
            if (n % 2 == 0) {
                n = n / 2;
                answer += n;
            } else {
                n = n / 2;
                answer += n;
                n++;
            }
        }

        return answer;
    }
}