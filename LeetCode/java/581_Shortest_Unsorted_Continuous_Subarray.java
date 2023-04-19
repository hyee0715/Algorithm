import java.util.Arrays;

class Solution {
    public int findUnsortedSubarray(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }

        int[] arr = new int[nums.length];
        int idx = 0;

        for (int n : nums) {
            arr[idx++] = n;
        }

        Arrays.sort(arr);

        int left = 0, right = nums.length - 1;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != nums[i]) {
                left = i;
                break;
            }
        }

        for (int i = arr.length - 1; i >= 0; i--) {
            if (arr[i] != nums[i]) {
                right = i;
                break;
            }
        }

        if (left == 0 && right == nums.length - 1 && arr[left] != nums[left] && arr[right] != nums[right]) {
            return nums.length;
        }

        if (left > right || (left == 0 && right == nums.length - 1)) {
            return 0;
        }

        return right - left + 1;
    }
}