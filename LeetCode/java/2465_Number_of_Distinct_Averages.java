import java.util.*;

class Solution {
    public int distinctAverages(int[] nums) {
        List<Integer> list = new ArrayList<>();

        for (int n : nums) {
            list.add(n);
        }

        Map<Double, Integer> map = new HashMap<>();

        while (list.size() > 0) {
            Collections.sort(list);

            int minNum = list.get(0);
            int maxNum = list.get(list.size() - 1);

            list.remove(0);
            list.remove(list.size() - 1);

            double avg = (double)(minNum + maxNum) / 2;
            map.put(avg, map.getOrDefault(avg, 0) + 1);
        }

        return map.size();
    }
}