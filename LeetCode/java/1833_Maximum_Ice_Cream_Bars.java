import java.util.Map;
import java.util.TreeMap;

class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int answer = 0;
        Map<Integer, Integer> map = new TreeMap<>();

        for (int cost : costs) {
            map.put(cost, map.getOrDefault(cost, 0) + 1);
        }

        for (int key : map.keySet()) {
            if (coins >= key) {
                for (int i = 0; i < map.get(key); i++) {
                    if (coins < key) {
                        break;
                    }

                    coins -= key;
                    answer++;
                }
            }
        }

        return answer;
    }
}