import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int minimumCardPickup(int[] cards) {
        int answer = Integer.MAX_VALUE;
        Map<Integer, List<Integer>> map = new HashMap<>(); //number, index

        for (int i = 0; i < cards.length; i++) {
            if (map.containsKey(cards[i])) {
                List<Integer> list = map.get(cards[i]);
                answer = Math.min(answer, i - list.get(list.size() - 1) + 1);
            }

            if (!map.containsKey(cards[i])) {
                map.put(cards[i], new ArrayList<>());
            }

            map.get(cards[i]).add(i);
        }

        if (answer == Integer.MAX_VALUE) {
            answer = -1;
        }

        return answer;
    }
}