class Solution {
    public int minimumRecolors(String blocks, int k) {
        int answer = Integer.MAX_VALUE, cnt = 0;

        for (int i = 0; i < blocks.length() - k + 1; i++) {
            cnt = 0;

            for (int j = i; j < i + k; j++) {
                if (blocks.charAt(j) == 'W') {
                    cnt++;
                }
            }

            answer = Math.min(answer, cnt);
        }

        return answer;
    }
}