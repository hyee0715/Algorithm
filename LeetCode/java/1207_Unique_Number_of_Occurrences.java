import java.util.HashMap;

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer, Integer> map1 = new HashMap<>();
        HashMap<Integer, Integer> map2 = new HashMap<>();

        for (int i = 0; i < arr.length; i++) {
            map1.put(arr[i], map1.getOrDefault(arr[i], 0) + 1);
        }

        for (int key : map1.keySet()) {
            map2.put(map1.get(key), map2.getOrDefault(map1.get(key), 0) + 1);
        }

        for (int key : map2.keySet()) {
            if (map2.get(key) > 1) {
                return false;
            }
        }

        return true;
    }
}