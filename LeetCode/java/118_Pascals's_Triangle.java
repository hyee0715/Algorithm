import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> nums = new ArrayList<>();

        for (int i = 0; i < numRows; i++) {
            List<Integer> list = new ArrayList<>();

            for (int j = 0; j <= i; j++) {
                list.add(0);
            }

            nums.add(list);
        }

        for (int i = 0; i < numRows; i++) {
            nums.get(i).set(0, 1);
            nums.get(i).set(i, 1);
        }

        for (int i = 2; i < nums.size(); i++) {
            for (int j = 1; j < nums.get(i).size() - 1; j++) {
                nums.get(i).set(j, nums.get(i - 1).get(j - 1) + nums.get(i - 1).get(j));
            }
        }

        return nums;
    }
}