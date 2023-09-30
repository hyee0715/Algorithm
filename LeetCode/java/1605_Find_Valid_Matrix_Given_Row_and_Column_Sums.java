class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int[][] answer = new int[rowSum.length][colSum.length];

        int[] curColSum = new int[colSum.length];
        int[] prevColSum = new int[colSum.length];

        for (int i = 0; i < rowSum.length; i++) {
            for (int j = 0; j < colSum.length; j++) {
                if (curColSum[j] < colSum[j] && rowSum[i] > 0) {
                    if (rowSum[i] <= (colSum[j] - curColSum[j])) {
                        curColSum[j] += rowSum[i];
                        rowSum[i] = 0;
                    } else {
                        rowSum[i] -= (colSum[j] - curColSum[j]);
                        curColSum[j] += (colSum[j] - curColSum[j]);
                    }
                }
            }

            for (int j = 0; j < curColSum.length; j++) {
                answer[i][j] = curColSum[j] - prevColSum[j];

                prevColSum[j] = curColSum[j];
            }
        }

        return answer;
    }
}