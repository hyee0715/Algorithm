import java.util.ArrayList;
import java.util.List;

class Solution {
    private void check(int[][] matrix, List<Integer> answer, boolean[][] visit, int mStart, int nStart, int mSize, int nSize) {
        if (mStart >= mSize || nStart >= nSize) {
            return;
        }

        if (mSize - mStart == 1 && nSize - mStart == 1) {
            if (visit[mStart][nStart] == false) {
                visit[mStart][nStart] = true;
                answer.add(matrix[mStart][nStart]);
            }

            return;
        }

        for (int i = nStart; i < nSize; i++) {
            if (visit[mStart][i] == false) {
                visit[mStart][i] = true;
                answer.add(matrix[mStart][i]);
            }
        }

        for (int i = mStart; i < mSize; i++) {
            if (visit[i][nSize - 1] == false) {
                visit[i][nSize - 1] = true;
                answer.add(matrix[i][nSize - 1]);
            }
        }

        for (int i = nSize - 1; i >= nStart; i--) {
            if (visit[mSize - 1][i] == false) {
                visit[mSize - 1][i] = true;
                answer.add(matrix[mSize - 1][i]);
            }
        }

        for (int i = mSize - 1; i >= mStart; i--) {
            if (visit[i][nStart] == false) {
                visit[i][nStart] = true;
                answer.add(matrix[i][nStart]);
            }
        }

        check(matrix, answer, visit, mStart + 1, nStart + 1, mSize - 1, nSize - 1);
    }

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> answer = new ArrayList<>();
        boolean[][] visit = new boolean[matrix.length][matrix[0].length];

        check(matrix, answer, visit, 0, 0, matrix.length, matrix[0].length);

        return answer;
    }
}