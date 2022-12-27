import java.util.Arrays;

class Solution {
    public void rotate(int[][] matrix) {
        int totalSize = matrix[0].length * matrix.length;
        int[] v = new int[totalSize];

        Arrays.fill(v, 0);

        int size = matrix.length;
        int idx = size - 1;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                v[idx + (size * j)] = matrix[i][j];
            }
            idx--;
        }

        int tempIdx = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                matrix[i][j] = v[tempIdx];
                tempIdx++;
            }
        }
    }
}