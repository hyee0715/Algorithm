import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.TreeSet;

class Solution {
    public int[] replaceElements(int[] arr) {
        List<Integer> answer = new ArrayList<>();
        int[] ret = new int[arr.length];
        TreeSet<Integer> set = new TreeSet<>(Collections.reverseOrder());

        for (int i = arr.length - 1; i >= 0; i--) {
            if (set.size() == 0) {
                set.add(arr[i]);
                answer.add(-1);
                continue;
            }

            answer.add(set.first());
            set.add(arr[i]);
        }

        Collections.reverse(answer);

        for (int i = 0; i < answer.size(); i++) {
            ret[i] = answer.get(i);
        }

        return ret;
    }
}