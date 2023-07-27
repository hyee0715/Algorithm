class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        int[][] answer = {};

        if (m * n != original.length) {
            return answer;
        }

        answer = new int[m][n];

        int idx = 0;
        for (int i = 0; i < answer.length; i++) {
            for (int j = 0; j < answer[0].length; j++) {
                answer[i][j] = original[idx++];
            }
        }

        return answer;
    }
}