import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int[] cnt = new int[mat.length];
        int[] answer = new int[k];
        List<List<Integer>> list = new ArrayList<>();

        for (int i = 0; i < mat.length; i++) {
            int count = 0;
            for (int j = 0; j < mat[i].length; j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }

            cnt[i] = count;
        }

        for (int i = 0; i < cnt.length; i++) {
            List<Integer> l = new ArrayList<>();
            l.add(cnt[i]);
            l.add(i);

            list.add(l);
        }

        Collections.sort(list, (x, y) -> {
            if (x.get(0) < y.get(0)) {
                return -1;
            }

            if (x.get(0) == y.get(0)) {
                return 0;
            }

            return 1;
        });

        for (int i = 0; i < list.size(); i++) {
            if (k == 0) {
                break;
            }

            answer[i] = list.get(i).get(1);
            k--;
        }

        return answer;
    }
}