class Solution {
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        int[][] answer = new int[mat1.length][mat2[0].length];

        for (int i = 0; i < mat1.length; i++) {
            for (int j = 0; j < mat2[0].length; j++) {
                for (int k = 0; k < mat1[0].length; k++) {
                    answer[i][j] += (mat1[i][k] * mat2[k][j]);
                }
            }
        }

        return answer;
    }
}