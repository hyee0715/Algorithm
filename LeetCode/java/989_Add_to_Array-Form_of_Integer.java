import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> nums = new ArrayList<>();
        for (int n : num) {
            nums.add(n);
        }

        int carry = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int n = k % 10;
            k = k / 10;

            int sum = n + nums.get(i) + carry;
            if (sum >= 10) {
                nums.set(i, sum % 10);
                carry = 1;
            } else {
                nums.set(i, sum);
                carry = 0;
            }
        }

        while (k > 0) {
            int n = k % 10;
            k = k / 10;

            int sum = n + carry;
            if (sum >= 10) {
                sum = sum % 10;
                nums.add(0, sum);
                carry = 1;
            } else {
                nums.add(0, sum);
                carry = 0;
            }
        }

        if (carry == 1) {
            nums.add(0, carry);
        }

        return nums;
    }
}