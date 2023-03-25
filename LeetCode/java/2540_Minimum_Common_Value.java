import java.util.Map;
import java.util.TreeMap;

class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int answer = -1;
        Map<Integer, Integer> map = new TreeMap<>();

        map.put(nums1[0], map.getOrDefault(nums1[0], 0) + 1);
        for (int i = 1; i < nums1.length; i++) {
            if (nums1[i - 1] == nums1[i]) {
                continue;
            }

            map.put(nums1[i], map.getOrDefault(nums1[i], 0) + 1);
        }

        map.put(nums2[0], map.getOrDefault(nums2[0], 0) + 1);
        for (int i = 1; i < nums2.length; i++) {
            if (nums2[i - 1] == nums2[i]) {
                continue;
            }

            map.put(nums2[i], map.getOrDefault(nums2[i], 0) + 1);
        }

        for (int key : map.keySet()) {
            if (map.get(key) > 1) {
                answer = key;
                break;
            }
        }

        return answer;
    }
}