class Solution {
    public int[][] modifiedMatrix(int[][] matrix) {
        int[] colMax = new int[matrix[0].length];

        for (int j = 0; j < matrix[0].length; j++) {
            int maxNum = -1;

            for (int i = 0; i < matrix.length; i++) {
                maxNum = Math.max(maxNum, matrix[i][j]);
            }

            for (int i = 0; i < matrix.length; i++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = maxNum;
                }
            }
        }

        return matrix;
    }
}