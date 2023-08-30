import java.util.ArrayList;
import java.util.List;

class Solution {
    public int triangularSum(int[] nums) {
        int answer = 0;

        List<Integer> list = new ArrayList<>();
        List<Integer> v = new ArrayList<>();

        for (int n : nums) {
            list.add(n);
        }

        while (list.size() > 1) {
            for (int i = 0; i < list.size() - 1; i++) {
                v.add((list.get(i) + list.get(i + 1)) % 10);
            }

            list.clear();
            for (int n : v) {
                list.add(n);
            }

            v.clear();
        }

        answer = list.get(0);
        return answer;
    }
}