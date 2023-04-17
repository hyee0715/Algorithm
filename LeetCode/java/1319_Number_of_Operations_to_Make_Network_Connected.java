import java.util.*;

class Solution {
    private void dfs(Map<Integer, List<Integer>> map, boolean[] visit, int prev, int cur, List<Pair> list) {
        if (prev != -1) {
            if (prev < cur) {
                list.add(new Pair(prev, cur));
            } else {
                list.add(new Pair(cur, prev));
            }
        }

        visit[cur] = true;

        List<Integer> current = map.get(cur);
        for (int i = 0; i < current.size(); i++) {
            if (visit[current.get(i)] == false) {
                dfs(map, visit, cur, current.get(i), list);
            }
        }
    }

    public int makeConnected(int n, int[][] connections) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        boolean[] visit = new boolean[n];
        List<Pair> list = new ArrayList<>();
        Set<Pair> set = new HashSet<>();

        for (int[] con : connections) {
            if (!map.containsKey(con[0])) {
                map.put(con[0], new ArrayList<>());
            }

            map.get(con[0]).add(con[1]);

            if (!map.containsKey(con[1])) {
                map.put(con[1], new ArrayList<>());
            }

            map.get(con[1]).add(con[0]);
        }

        for (int[] con : connections) {
            set.add(new Pair(con[0], con[1]));
        }

        int connectionCnt = 0;
        for (int key : map.keySet()) {
            if (visit[key] == false) {
                dfs(map, visit, -1, key, list);
                connectionCnt++;
            }
        }

        for (Pair p : list) {
            set.remove(p);
        }

        int notVisitCnt = n - map.size();
        if (set.size() < notVisitCnt + connectionCnt - 1) {
            return -1;
        }

        return notVisitCnt + connectionCnt - 1;
    }
}

class Pair {
    int x;
    int y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    @Override
    public boolean equals(Object ob)
    {
        if (ob == this) {
            return true;
        }

        if (ob == null || ob.getClass() != getClass()) {
            return false;
        }

        Pair p = (Pair) ob;
        return Objects.equals(x, p.x) && p.y == y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }

    @Override
    public String toString() {
        return "{" + x + ", " + y + "}";
    }
}