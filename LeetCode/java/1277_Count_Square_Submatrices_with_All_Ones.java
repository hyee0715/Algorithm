class Solution {
    public int countSquares(int[][] matrix) {
        int answer = 0;
        int minLength = Math.min(matrix.length, matrix[0].length);

        for (int i = 1; i <= minLength; i++) {
            for (int j = 0; j <= matrix.length - i; j++) {
                for (int k = 0; k <= matrix[j].length - i; k++) {
                    if (check(matrix, j, k, i)) {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }

    private boolean check(int[][] matrix, int x, int y, int length) {
        for (int a = 0; a < length; a++) {
            for (int b = 0; b < length; b++) {
                if (matrix[x + a][y + b] == 0) {
                    return false;
                }
            }
        }

        return true;
    }
}