import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> answer = new ArrayList<>();
        List<List<Integer>> nums = new ArrayList<>();

        for (int i = 0; i < rowIndex + 1; i++) {
            List<Integer> list = new ArrayList<>();

            for (int j = 0; j <= i; j++) {
                list.add(0);
            }

            nums.add(list);
        }

        for (int i = 0; i <= rowIndex; i++) {
            nums.get(i).set(0, 1);
            nums.get(i).set(i, 1);
        }

        for (int i = 2; i < nums.size(); i++) {
            for (int j = 1; j < nums.get(i).size() - 1; j++) {
                nums.get(i).set(j, nums.get(i - 1).get(j - 1) + nums.get(i - 1).get(j));
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            answer.add(nums.get(nums.size() - 1).get(i));
        }

        return answer;
    }
}