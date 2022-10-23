class Solution {
    public int diagonalSum(int[][] mat) {
        int answer = 0;

        for (int i = 0; i < mat.length; i++) {
            answer += mat[i][i];
            answer += mat[i][mat.length - 1 - i];
        }

        if (mat.length % 2 == 1) {
            int sub = mat.length / 2;
            answer -= mat[sub][sub];
        }

        return answer;
    }
}