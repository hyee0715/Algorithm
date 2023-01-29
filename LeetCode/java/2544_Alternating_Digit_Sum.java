class Solution {
    public int alternateDigitSum(int n) {
        int answer = 0;

        String num = String.valueOf(n);

        for (int i = 0; i < num.length(); i++) {
            if (i % 2 == 0) {
                answer += (num.charAt(i) - '0');
                continue;
            }

            answer -= (num.charAt(i) - '0');
        }

        return answer;
    }
}