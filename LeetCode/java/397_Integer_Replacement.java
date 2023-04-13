import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private int bfs(int n) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(n, 0));

        while (!q.isEmpty()) {
            Pair current = q.poll();
            long x = current.getNum();
            int cnt = current.getCount();

            if (x == 1) {
                return cnt;
            }

            if (x % 2 == 0) {
                long nx = x / 2;

                if (nx < 0) {
                    continue;
                }

                q.add(new Pair(nx, cnt + 1));
            } else {
                long nx = x - 1;

                if (nx < 0) {
                    continue;
                }

                q.add(new Pair(nx, cnt + 1));

                nx = x + 1;

                if (nx < 0 || nx > (long)n + 1) {
                    continue;
                }

                q.add(new Pair(nx, cnt + 1));
            }
        }

        return 0;
    }

    public int integerReplacement(int n) {
        return bfs(n);
    }
}

class Pair {
    long num;
    int count;

    Pair(long num, int count) {
        this.num = num;
        this.count = count;
    }

    long getNum() {
        return num;
    }

    int getCount() {
        return count;
    }
}