import java.util.Arrays;
import java.util.Stack;

class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] answer = new int[nums1.length];
        Stack<Integer> stack = new Stack<>();
        boolean flag = false;

        Arrays.fill(answer, -1);

        for (int i = 0; i < nums1.length; i++) {
            while (!stack.isEmpty()) {
                stack.pop();
            }

            flag = false;

            for (int j = 0; j < nums2.length; j++) {
                if (nums1[i] > nums2[j]) {
                    stack.push(nums2[j]);
                    continue;
                }

                if (nums1[i] == nums2[j]) {
                    flag = true;
                    stack.push(nums2[j]);
                    continue;
                }

                if (flag == true) {
                    answer[i] = nums2[j];
                    break;
                } else {
                    stack.push(nums2[j]);
                }
            }
        }

        return answer;
    }
}