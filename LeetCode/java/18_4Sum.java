import java.util.*;

class Solution {
    private List<List<Integer>> twoSum(int[] nums, int target, int first, int second) {
        List<List<Integer>> answer = new ArrayList<>();

        int left = second + 1, right = nums.length - 1;

        while (left < right) {
            long sum = 0;
            sum += nums[first];
            sum += nums[second];
            sum += nums[left];
            sum += nums[right];

            if (sum == target) {
                List<Integer> list = new ArrayList<>(Arrays.asList(nums[first], nums[second], nums[left], nums[right]));
                answer.add(list);

                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return answer;
    }

    private List<List<Integer>> threeSum(int[] nums, int target, int first) {
        List<List<Integer>> answer = new ArrayList<>();

        for (int i = first + 1; i < nums.length - 1; i++) {
            List<List<Integer>> list = twoSum(nums, target, first, i);

            for (List<Integer> l : list) {
                answer.add(l);
            }
        }

        return answer;
    }

    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> answer = new ArrayList<>();

        if (nums.length == 1 && target == nums[0]) {
            return answer;
        }

        Set<List<Integer>> set = new HashSet<>();

        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; i++) {
            List<List<Integer>> list = threeSum(nums, target, i);

            for (List<Integer> l : list) {
                set.add(l);
            }
        }

        for (List<Integer> s : set) {
            answer.add(s);
        }

        return answer;
    }
}