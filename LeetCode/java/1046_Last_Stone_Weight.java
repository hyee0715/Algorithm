import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int lastStoneWeight(int[] stones) {
        List<Integer> list = new ArrayList<>();

        for (int n : stones) {
            list.add(n);
        }

        int answer = 0;

        while (list.size() > 1) {
            Collections.sort(list);

            int heaviest1 = list.get(list.size() - 1);
            int heaviest2 = list.get(list.size() - 2);

            list.remove(list.size() - 2);
            list.remove(list.size() - 1);

            if (heaviest1 != heaviest2) {
                list.add(heaviest1 - heaviest2);
            }
        }

        if (list.size() == 1) {
            answer = list.get(list.size() - 1);
        }

        return answer;
    }
}