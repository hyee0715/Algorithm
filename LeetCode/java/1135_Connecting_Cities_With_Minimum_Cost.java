import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    List<int[]> cities = new ArrayList<>();
    int[] parent;

    public int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }

        parent[x] = findParent(parent[x]);

        return parent[x];
    }

    public boolean sameParent(int x, int y) {
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

    public int minimumCost(int n, int[][] connections) {
        int cost = 0;

        for (int[] connection : connections) {
            cities.add(new int[]{connection[2], connection[0], connection[1]});
        }

        parent = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        Collections.sort(cities, (x, y) -> {
            if (x[0] < y[0]) {
                return -1;
            }

            if (x[0] > y[0]) {
                return 1;
            }

            return 0;
        });

        for (int i = 0; i < cities.size(); i++) {
            int[] city = cities.get(i);
            if (!sameParent(city[1], city[2])) {
                unionParent(city[1], city[2]);
                cost += city[0];
            }
        }

        for (int i = 1; i < parent.length; i++) {
            parent[i] = findParent(parent[i]);
        }

        for (int i = 1; i < parent.length - 1; i++) {
            if (parent[i] != parent[i + 1]) {
                cost = -1;
                break;
            }
        }

        return cost;
    }
}