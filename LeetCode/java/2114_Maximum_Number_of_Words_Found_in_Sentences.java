class Solution {
    public int mostWordsFound(String[] sentences) {
        int answer = -1;

        for (int i = 0; i < sentences.length; i++) {
            int cnt = 1;

            for (int j = 0; j < sentences[i].length(); j++) {
                if (sentences[i].charAt(j) == ' ') {
                    cnt++;
                }
            }

            answer = Math.max(answer, cnt);
        }

        return answer;
    }
}