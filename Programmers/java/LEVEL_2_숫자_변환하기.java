import java.util.*;

class Solution {
    private int bfs(int x, int y, int n, boolean[] visit) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{x, 0});
        visit[x] = true;

        while (!q.isEmpty()) {
            int[] qx = q.poll();
            int num = qx[0];
            int cnt = qx[1];

            if (num == y) {
                return cnt;
            }

            int nextNum = num + n;
            if (nextNum <= y && visit[nextNum] == false) {
                q.add(new int[]{nextNum, cnt + 1});
                visit[nextNum] = true;
            }

            nextNum = num * 2;
            if (nextNum <= y && visit[nextNum] == false) {
                q.add(new int[]{nextNum, cnt + 1});
                visit[nextNum] = true;
            }

            nextNum = num * 3;
            if (nextNum <= y && visit[nextNum] == false) {
                q.add(new int[]{nextNum, cnt + 1});
                visit[nextNum] = true;
            }
        }

        return -1;
    }

    public int solution(int x, int y, int n) {
        int answer = 0;
        boolean[] visit = new boolean[y + 1];

        answer = bfs(x, y, n, visit);
        return answer;
    }
}