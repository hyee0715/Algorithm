import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private void twoSum(int[] nums, int idx, List<List<Integer>> answer) {
        int left = idx + 1;
        int right = nums.length - 1;

        while (left < right) {
            if (nums[idx] + nums[left] + nums[right] == 0) {
                List<Integer> list = new ArrayList<>(Arrays.asList(nums[idx], nums[left], nums[right]));

                answer.add(list);

                left++;
                right--;

                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            } else if (nums[idx] + nums[left] + nums[right] < 0) {
                left++;
            } else {
                right--;

                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            }
        }
    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> answer = new ArrayList<>();

        Arrays.sort(nums);

        for (int i = 0; i < nums.length; i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSum(nums, i, answer);
            }
        }

        return answer;
    }
}