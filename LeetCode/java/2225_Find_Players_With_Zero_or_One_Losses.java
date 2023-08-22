import java.util.*;

class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        List<List<Integer>> answer = new ArrayList<>();
        List<Integer> ans1 = new ArrayList<>();
        List<Integer> ans2 = new ArrayList<>();
        Map<Integer, Integer> lose = new HashMap<>();

        for (int[] match : matches) {
            lose.put(match[1], lose.getOrDefault(match[1], 0) + 1);
        }

        for (int key : lose.keySet()) {
            if (lose.get(key) == 1) {
                ans2.add(key);
            }
        }

        Set<Integer> winners = new HashSet<>();
        for (int[] match : matches) {
            if (!lose.containsKey(match[0])) {
                winners.add(match[0]);
            }
        }

        for (int st : winners) {
            ans1.add(st);
        }

        Collections.sort(ans1);
        Collections.sort(ans2);
        answer.add(ans1);
        answer.add(ans2);

        return answer;
    }
}