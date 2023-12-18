import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
    public int minProductSum(int[] nums1, int[] nums2) {
        int answer = 0;

        List<Integer> list = new ArrayList<>();
        for (int n : nums2) {
            list.add(n);
        }

        Collections.sort(list, Collections.reverseOrder());

        int idx = 0;
        for (int l : list) {
            nums2[idx++] = l;
        }

        Arrays.sort(nums1);

        for (int i = 0; i < nums1.length; i++) {
            answer += (nums1[i] * nums2[i]);
        }

        return answer;
    }
}