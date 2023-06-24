import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

class Solution {
    void dfs(int cnt, int[] digits, boolean[] visit, List<Integer> list, Set<Integer> set) {
        if (cnt == 3) {
            if (list.get(0) == 0 || list.get(2) % 2 != 0) {
                return;
            }

            int num = 0;
            for (int n : list) {
                num = num * 10 + n;
            }

            set.add(num);
        } else {
            for (int i = 0; i < digits.length; i++) {
                if (visit[i] == true) {
                    continue;
                }
                visit[i] = true;
                list.add(digits[i]);
                dfs(cnt + 1, digits, visit, list, set);
                list.remove(list.size() - 1);
                visit[i] = false;
            }
        }
    }

    public int[] findEvenNumbers(int[] digits) {

        boolean[] visit = new boolean[digits.length];
        List<Integer> list = new ArrayList<>();
        Set<Integer> set = new TreeSet<>();

        dfs(0, digits, visit, list, set);

        int[] answer = new int[set.size()];

        int idx = 0;
        for (int n : set) {
            answer[idx++] = n;
        }

        return answer;
    }
}