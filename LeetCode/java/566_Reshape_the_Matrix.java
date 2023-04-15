class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        if (r * c != mat.length * mat[0].length) {
            return mat;
        }

        int[][] answer = new int[r][c];

        int rIdx = 0;
        int cIdx = 0;

        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                answer[rIdx][cIdx++] = mat[i][j];

                if (cIdx == c) {
                    rIdx++;
                    cIdx = 0;
                }
            }
        }

        return answer;
    }
}