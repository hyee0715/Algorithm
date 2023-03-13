import java.util.*;

class Solution {
    List<Edges> edges;
    int[] parent;

    int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }

        parent[x] = findParent(parent[x]);

        return parent[x];
    }

    boolean sameParent(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x == y) {
            return true;
        }

        return false;
    }

    void unionParent(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x < y) {
            parent[y] = x;
        } else {
            parent[x] = y;
        }
    }

    public int solution(int n, int[][] costs) {
        int answer = 0;

        edges = new ArrayList<>();
        parent = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < costs.length; i++) {
            int x = costs[i][0];
            int y = costs[i][1];
            int cost = costs[i][2];

            edges.add(new Edges(cost, x, y));
            edges.add(new Edges(cost, y, x));
        }

        Collections.sort(edges);

        for (int i = 0; i < edges.size(); i++) {
            if (!sameParent(edges.get(i).getX(), edges.get(i).getY())) {
                unionParent(edges.get(i).getX(), edges.get(i).getY());
                answer += edges.get(i).getCost();
            }
        }

        return answer;
    }
}

class Edges implements Comparable<Edges> {
    int cost;
    int x;
    int y;

    Edges(int cost, int x, int y) {
        this.cost = cost;
        this.x = x;
        this.y = y;
    }

    int getCost() {
        return cost;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    @Override
    public int compareTo(Edges e) {
        if (this.cost < e.cost) {
            return -1;
        }

        if (this.cost > e.cost) {
            return 1;
        }

        return 0;
    }
}