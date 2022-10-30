import java.util.ArrayList;
import java.util.List;

class Solution {
    public boolean areNumbersAscending(String s) {
        String[] str = s.split(" ");
        List<Integer> nums = new ArrayList<>();

        for (int i = 0; i < str.length; i++) {
            if (str[i].charAt(0) >= '0' && str[i].charAt(0) <= '9') {
                nums.add(Integer.parseInt(str[i]));
            }
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums.get(i) >= nums.get(i + 1)) {
                return false;
            }
        }

        return true;
    }
}