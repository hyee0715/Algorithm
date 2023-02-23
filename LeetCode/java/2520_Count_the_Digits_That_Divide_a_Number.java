class Solution {
    public int countDigits(int num) {
        int answer = 0;
        String s = String.valueOf(num);

        for (int i = 0; i < s.length(); i++) {
            if (num % (s.charAt(i) - '0') == 0) {
                answer++;
            }
        }

        return answer;
    }
}