import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        List<Integer> tempAnswer = new ArrayList<>();
        int[] answer;
        Queue<int[]> q = new LinkedList<>();

        int[] dx = {1, 0};
        int[] dy = {0, 1};

        q.add(new int[] {0, 0});
        tempAnswer.add(nums.get(0).get(0));

        nums.get(0).set(0, -1);

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];

            for (int i = 0; i < 2; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= nums.size() || ny >= nums.get(nx).size()) {
                    continue;
                }

                if (nums.get(nx).get(ny) != -1) {
                    q.add(new int[] {nx, ny});
                    tempAnswer.add(nums.get(nx).get(ny));
                    nums.get(nx).set(ny, -1);
                }
            }
        }

        answer = new int[tempAnswer.size()];
        int idx = 0;
        for (int n : tempAnswer) {
            answer[idx++] = n;
        }

        return answer;
    }
}