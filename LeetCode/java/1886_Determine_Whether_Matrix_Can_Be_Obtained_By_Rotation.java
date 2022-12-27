import java.util.ArrayList;
import java.util.List;

class Solution {
    private boolean check(int[][] target, int[][] sample) {
        for (int i = 0; i < target.length; i++) {
            for (int j = 0; j < target[i].length; j++) {
                if (target[i][j] != sample[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    public boolean findRotation(int[][] mat, int[][] target) {
        int[][] v1 = new int[mat.length][mat.length];
        int[][] v2 = new int[mat.length][mat.length];
        int[][] v3 = new int[mat.length][mat.length];

        List<Integer> temp = new ArrayList<>();
        for (int i = 0; i < mat.length; i++) {
            temp.clear();
            for (int j = 0; j < mat[i].length; j++) {
                temp.add(mat[i][j]);
            }

            int tempIdx = 0;
            int endPoint = mat[i].length - 1 - i;
            for (int j = 0; j < mat[i].length; j++) {
                v1[j][endPoint] = temp.get(tempIdx);
                tempIdx++;
            }

            tempIdx = 0;
            endPoint = mat[i].length - 1 - i;
            for (int j = mat[i].length - 1; j >= 0; j--) {
                v2[endPoint][j] = temp.get(tempIdx);
                tempIdx++;
            }

            tempIdx = 0;
            endPoint = i;
            for (int j = mat[i].length - 1; j >= 0; j--) {
                v3[j][endPoint] = temp.get(tempIdx);
                tempIdx++;
            }
        }

        if (check(target, mat) || check(target, v1) || check(target, v2) || check(target, v3)) {
            return true;
        }

        return false;
    }
}