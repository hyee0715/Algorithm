class Solution {
    public int findTheLongestBalancedSubstring(String s) {
        int answer = 0;
        int zero = 0;
        int one = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0' && one > 0) {
                zero = 0;
                one = 0;
            }

            if (s.charAt(i) == '0') {
                zero++;
            } else {
                one++;
            }

            if (zero == one) {
                answer = Math.max(answer, zero + one);
            } else {
                answer = Math.max(answer, Math.min(zero, one) * 2);
            }
        }

        return answer;
    }
}