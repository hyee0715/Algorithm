import java.util.HashSet;
import java.util.Set;

class Solution {
    public int countDistinctIntegers(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for (int n : nums) {
            set.add(n);

            String s = String.valueOf(n);

            StringBuilder sb = new StringBuilder(s);

            sb.reverse();

            set.add(Integer.parseInt(sb.toString()));
        }

        return set.size();
    }
}