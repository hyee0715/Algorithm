import java.util.*;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        List<Pair> cnt = new ArrayList<>();
        int[] answer = new int[k];

        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }

        for (int key : map.keySet()) {
            Pair pair = new Pair(key, map.get(key));
            cnt.add(pair);
        }

        Collections.sort(cnt);

        for (int i = 0; i < k; i++) {
            answer[i] = cnt.get(i).number;
        }

        return answer;
    }
}

class Pair implements Comparable<Pair> {
    int number;
    int count;

    Pair(int number, int count) {
        this.number = number;
        this.count = count;
    }

    @Override
    public int compareTo(Pair o) {
        if (this.count < o.count) {
            return 1;
        }

        if (this.count > o.count) {
            return -1;
        }

        return 0;
    }
}