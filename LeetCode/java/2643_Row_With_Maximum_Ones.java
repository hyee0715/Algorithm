class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int[] answer = new int[2];
        int maxRow = -1;
        int maxOneCnt = -1;

        for (int i = 0; i < mat.length; i++) {
            int cnt = 0;

            for (int j = 0; j < mat[i].length; j++) {
                if (mat[i][j] == 1) {
                    cnt++;
                }
            }

            if (maxOneCnt < cnt) {
                maxOneCnt = cnt;
                maxRow = i;
            }
        }

        answer[0] = maxRow;
        answer[1] = maxOneCnt;

        return answer;
    }
}