import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        List<Integer> answer = new ArrayList<>();
        Map<Integer, Integer> m1 = new HashMap<>();
        Map<Integer, Integer> m2 = new HashMap<>();
        Map<Integer, Integer> m3 = new HashMap<>();
        Map<Integer, Integer> m4 = new HashMap<>();

        for (int i = 0; i < nums1.length; i++) {
            m1.put(nums1[i], m1.getOrDefault(nums1[i], 0) + 1);
        }

        for (int i = 0; i < nums2.length; i++) {
            m2.put(nums2[i], m2.getOrDefault(nums2[i], 0) + 1);
        }

        for (int i = 0; i < nums3.length; i++) {
            m3.put(nums3[i], m3.getOrDefault(nums3[i], 0) + 1);
        }

        for (int key : m1.keySet()) {
            m4.put(key, m4.getOrDefault(key, 0) + 1);
        }

        for (int key : m2.keySet()) {
            m4.put(key, m4.getOrDefault(key, 0) + 1);
        }

        for (int key : m3.keySet()) {
            m4.put(key, m4.getOrDefault(key, 0) + 1);
        }

        for (int key : m4.keySet()) {
            if (m4.get(key) >= 2) {
                answer.add(key);
            }
        }

        return answer;
    }
}