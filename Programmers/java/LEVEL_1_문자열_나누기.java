class Solution {
    public int solution(String s) {
        int answer = 0;

        char init = s.charAt(0);
        int initCnt = 0;
        int cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == init) {
                initCnt++;
            } else {
                cnt++;
            }

            if (initCnt == cnt) {
                answer++;
                initCnt = 0;
                cnt = 0;

                if (i < s.length() - 1) {
                    init = s.charAt(i + 1);
                }
            }
        }

        if (initCnt > 0 || cnt > 0) {
            answer++;
        }

        return answer;
    }
}