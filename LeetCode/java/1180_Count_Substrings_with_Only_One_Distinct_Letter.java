class Solution {
    public int countLetters(String s) {
        int answer = 1, cnt = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) == s.charAt(i)) {
                cnt++;
            } else {
                cnt = 1;
            }

            answer += cnt;
        }

        return answer;
    }
}