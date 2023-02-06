import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<List<Integer>> answer = new ArrayList<>();
        Set<Integer> s1 = new HashSet<>();
        Set<Integer> s2 = new HashSet<>();

        for (int i = 0; i < nums1.length; i++) {
            s1.add(nums1[i]);
        }

        for (int i = 0; i < nums2.length; i++) {
            s2.add(nums2[i]);
        }

        List<Integer> list = new ArrayList<>();
        for (int s : s1) {
            if (!s2.contains(s)) {
                list.add(s);
            }
        }

        answer.add(list);
        list = new ArrayList<>();

        for (int s : s2) {
            if (!s1.contains(s)) {
                list.add(s);
            }
        }

        answer.add(list);
        return answer;
    }
}