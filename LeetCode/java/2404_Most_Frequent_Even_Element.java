import java.util.HashMap;
import java.util.Map;

class Solution {
    public int mostFrequentEven(int[] nums) {
        int answer = -1;
        Map<Integer, Integer> map = new HashMap<>();
        MinPair minPair = new MinPair(100002, -1);

        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for (int key : map.keySet()) {
            if (key % 2 == 0) {
                if (map.get(key) > minPair.count) {
                    minPair.setNumber(key);
                    minPair.setCount(map.get(key));
                    continue;
                }

                if (map.get(key) == minPair.count) {
                    if (key < minPair.number) {
                        minPair.setNumber(key);
                        minPair.setCount(map.get(key));
                    }
                }
            }
        }

        if (minPair.number != 100002) {
            answer = minPair.number;
        }

        return answer;
    }
}

class MinPair {
    int number;
    int count;

    MinPair(int number, int count) {
        this.number = number;
        this.count = count;
    }

    void setNumber(int number) {
        this.number = number;
    }

    void setCount(int count) {
        this.count = count;
    }
}