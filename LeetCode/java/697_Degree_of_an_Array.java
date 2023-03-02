import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findShortestSubArray(int[] nums) {
        if (nums.length == 1) {
            return 1;
        }

        int answer = Integer.MAX_VALUE;
        Map<Integer, Integer> numsMap = new HashMap<>();
        int maxCnt = 0, cnt = 0;

        for (int n : nums) {
            numsMap.put(n, numsMap.getOrDefault(n, 0) + 1);
        }

        for (int key : numsMap.keySet()) {
            maxCnt = Math.max(maxCnt, numsMap.get(key));
        }

        Map<Integer, Integer> curMap = new HashMap<>();
        int left = 0, right = 0;
        curMap.put(nums[left], curMap.getOrDefault(nums[left], 0) + 1);

        while (left < nums.length - 1 || right < nums.length - 1) {
            cnt = 0;
            for (int key : curMap.keySet()) {
                cnt = Math.max(cnt, curMap.get(key));
            }

            if (cnt < maxCnt) {
                right++;

                if (right >= nums.length) {
                    break;
                }

                curMap.put(nums[right], curMap.getOrDefault(nums[right], 0) + 1);
            } else {
                answer= Math.min(answer, right - left + 1);
                curMap.put(nums[left], curMap.getOrDefault(nums[left], 0) - 1);
                left++;
            }
        }

        return answer;
    }
}