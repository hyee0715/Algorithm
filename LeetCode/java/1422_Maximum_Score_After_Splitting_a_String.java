class Solution {
    public int maxScore(String s) {
        int answer = -1;

        int cnt = 1;
        for (int i = 0; i < s.length() - 1; i++) {
            int left = 0, right = 0;

            for (int j = 0; j < cnt; j++) {
                if (s.charAt(j) == '0') {
                    left++;
                }
            }

            for (int j = cnt; j < s.length(); j++) {
                if (s.charAt(j) == '1') {
                    right++;
                }
            }

            cnt++;
            int score = left + right;
            answer = Math.max(answer, score);
        }

        return answer;
    }
}