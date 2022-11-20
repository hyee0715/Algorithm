class Solution {
    public String largestOddNumber(String num) {
        StringBuilder answer = new StringBuilder();
        int idx = -1;

        for (int i = num.length() - 1; i >= 0; i--) {
            if ((num.charAt(i) - '0') % 2 != 0) {
                idx = i;
                break;
            }
        }

        for (int i = 0; i <= idx; i++) {
            answer.append(num.charAt(i));
        }

        return answer.toString();
    }
}