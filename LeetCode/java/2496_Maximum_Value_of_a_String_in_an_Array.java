class Solution {
    private boolean allDigits(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < '0' || s.charAt(i) > '9') {
                return false;
            }
        }

        return true;
    }

    public int maximumValue(String[] strs) {
        int answer = 0;

        for (String s : strs) {
            if (allDigits(s)) {
                answer = Math.max(answer, Integer.parseInt(s));
            } else {
                answer = Math.max(answer, s.length());
            }
        }

        return answer;
    }
}