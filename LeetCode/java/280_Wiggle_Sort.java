import java.util.Arrays;

class Solution {
    private void swap(int i, int j, int[] nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public void wiggleSort(int[] nums) {
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 1; i++) {
            if (i % 2 != 0) {
                swap(i, i + 1, nums);
            }
        }
    }
}