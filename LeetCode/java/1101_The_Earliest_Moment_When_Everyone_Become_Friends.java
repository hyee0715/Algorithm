class Solution {
    private int[] parent;

    public int earliestAcq(int[][] logs, int n) {
        int answer = -1;

        Arrays.sort(logs, (x, y) -> {
            int x1 = x[0];
            int y1=  y[0];

            if (x1 < y1) {
                return -1;
            }

            if (x1 > y1) {
                return 1;
            }

            return 0;
        });

        initParent(n);

        for (int[] log : logs) {
            int moment = log[0];
            int a = log[1];
            int b = log[2];

            if (!sameParent(a, b)) {
                unionParent(a, b);
            }

            if (allSameParent(n)) {
                answer = moment;

                break;
            }
        }

        return answer;
    }

    void initParent(int n) {
        parent = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int n) {
        if (parent[n] == n) {
            return n;
        }

        int ret = findParent(parent[n]);

        return ret;
    }

    boolean sameParent(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if (a == b) {
            return true;
        }

        return false;
    }

    void unionParent(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if (a < b) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
    }

    boolean allSameParent(int n) {
        for (int i = 0; i < n - 1; i++) {
            if (!sameParent(i, i + 1)) {
                return false;
            }
        }

        return true;
    }
}