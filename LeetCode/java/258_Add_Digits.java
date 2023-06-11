class Solution {
    public int addDigits(int num) {
        int cnt = 0;
        String s = String.valueOf(num);

        while (s.length() > 1) {
            cnt = 0;
            for (int i = 0; i < s.length(); i++) {
                cnt += (s.charAt(i) - '0');
            }

            s = String.valueOf(cnt);
        }

        int answer = s.charAt(0) - '0';
        return answer;
    }
}