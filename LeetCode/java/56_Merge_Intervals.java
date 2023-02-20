import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[][] merge(int[][] intervals) {
        List<List<Integer>> answerList = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        int[][] answer;

        if (intervals.length == 1) {
            answer = new int[1][2];
            answer[0][0] = intervals[0][0];
            answer[0][1] = intervals[0][1];

            return answer;
        }

        Arrays.sort(intervals, (x, y) -> {
            if (x[0] < y[0]) {
                return -1;
            }

            if (x[0] > y[0]) {
                return 1;
            }

            return 0;
        });

        list.add(intervals[0][0]);
        list.add(intervals[0][1]);

        for (int i = 1; i < intervals.length; i++) {
            if (list.get(1) < intervals[i][0]) {
                answerList.add(list);

                list = new ArrayList<>();
                list.add(intervals[i][0]);
                list.add(intervals[i][1]);
            }

            if (list.get(1) >= intervals[i][0] && list.get(1) <= intervals[i][1]) {
                list.set(1, intervals[i][1]);
            }

            if (i == intervals.length - 1) {
                answerList.add(list);
            }
        }

        answer = new int[answerList.size()][answerList.get(0).size()];

        for (int i = 0; i < answerList.size(); i++) {
            for (int j = 0; j < answerList.get(i).size(); j++) {
                answer[i][j] = answerList.get(i).get(j);
            }
        }

        return answer;
    }
}