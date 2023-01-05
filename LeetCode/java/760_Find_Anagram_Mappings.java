import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution {
    public int[] anagramMappings(int[] nums1, int[] nums2) {
        int[] answer = new int[nums1.length];
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < nums2.length; i++) {
            if (!map.containsKey(nums2[i])) {
                map.put(nums2[i], new ArrayList<Integer>());
            }

            map.get(nums2[i]).add(i);
        }

        int idx = 0;
        for (int i = 0; i < nums1.length; i++) {
            int n = map.get(nums1[i]).get(0);
            answer[idx] = n;
            idx++;

            map.get(nums1[i]).remove(map.get(nums1[i]));
        }

        return answer;
    }
}