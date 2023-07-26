import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int tupleSameProduct(int[] nums) {
        int answer = 0;
        Map<Integer, List<int[]>> map = new HashMap<>();

        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (!map.containsKey(nums[i] * nums[j])) {
                    map.put(nums[i] * nums[j], new ArrayList<>());
                }

                map.get(nums[i] * nums[j]).add(new int[]{nums[i], nums[j]});
            }
        }

        for (int key : map.keySet()) {
            if (map.get(key).size() > 1) {
                int n = map.get(key).size();

                int num = (n * (n - 1)) / 2;
                answer += num * 8;
            }
        }

        return answer;
    }
}