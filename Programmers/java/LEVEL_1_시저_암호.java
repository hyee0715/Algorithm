class Solution {
    private boolean isCapitalLetter(char c) {
        if (c >= 'A' && c <= 'Z') {
            return true;
        }

        return false;
    }

    public String solution(String s, int n) {
        String answer = "";

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                answer += s.charAt(i);
                continue;
            }

            int num = s.charAt(i) + n;
            int zNum = 'Z';
            int smallZNum = 'z';

            if (isCapitalLetter(s.charAt(i))) {
                if (num > zNum) {
                    int cnt = num - zNum;

                    answer += (char)('A' + cnt - 1);
                } else {
                    answer += (char)(s.charAt(i) + n);
                }
            } else {
                if (num > smallZNum) {
                    int cnt = num - smallZNum;

                    answer += (char)('a' + cnt - 1);
                } else {
                    answer += (char)(s.charAt(i) + n);
                }
            }
        }

        return answer;
    }
}