import java.util.ArrayList;
import java.util.List;

class Solution {
    private int calculateSum(List<Integer> v) {
        int sum = 0;

        for (int n : v) {
            sum += n;
        }

        return sum;
    }

    private void copy(List<List<Integer>> answer, List<List<Integer>> temp) {
        for (List<Integer> t : temp) {
            List<Integer> list = new ArrayList<>();

            for (int n : t) {
                list.add(n);
            }

            answer.add(list);
        }
    }

    private List<List<Integer>> check(int idx, int cnt, int[] candidates, int target, List<Integer> v) {
        List<List<Integer>> answer = new ArrayList<>();
        List<List<Integer>> temp = new ArrayList<>();

        if (calculateSum(v) == target) {
            answer.add(v);
            return answer;
        }

        if (calculateSum(v) > target) {
            return answer;
        }

        for (int i = idx; i < candidates.length; i++) {
            v.add(candidates[i]);
            temp = check(i, cnt + 1, candidates, target, v);
            copy(answer, temp);
            v.remove(v.size() - 1);
        }

        return answer;
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> v = new ArrayList<>();

        List<List<Integer>> answer = check(0, 0, candidates, target, v);

        return answer;
    }
}