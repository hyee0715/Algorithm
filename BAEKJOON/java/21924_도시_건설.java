import java.io.*;
import java.util.*;

public class Main {
    public static int n, m;
    public static Long allPathSum = 0L, minimumCost = 0L;
    public static List<Path> paths = new ArrayList<>();
    public static List<Integer> parent = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int pathA = Integer.parseInt(st.nextToken());
            int pathB = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            Path path = new Path(pathA, pathB, cost);
            paths.add(path);

            allPathSum += cost;
        }
    }

    private static void solution() throws IOException {
        parentInitialize();

        Collections.sort(paths);

        for (int i = 0; i < paths.size(); i++) {
            if (sameParent(paths.get(i).pathA, paths.get(i).pathB) == false) {
                unionParent(paths.get(i).pathA, paths.get(i).pathB);

                minimumCost += paths.get(i).cost;
            }
        }

        if (!arePathsAllConnected()) {
            bw.write(String.valueOf(-1));
            return;
        }

        bw.write(String.valueOf(allPathSum - minimumCost));
    }

    private static void parentInitialize() {
        parent.add(-1);

        for (int i = 1; i <= n; i++) {
            parent.add(i);
        }
    }

    private static int findParent(int x) {
        if (parent.get(x) == x) return x;
        else {
            parent.set(x, findParent(parent.get(x)));
            return parent.get(x);
        }
    }

    private static void unionParent(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x < y)
            parent.set(y, x);
        else
            parent.set(x, y);
    }

    private static boolean sameParent(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x == y)
            return true;
        return false;
    }

    private static boolean arePathsAllConnected() {
        for (int i = 1; i < n; i++) {
            if (!sameParent(i, i + 1))
                return false;
        }

        return true;
    }

    static class Path implements Comparable<Path> {
        int pathA;
        int pathB;
        int cost;

        public Path(int pathA, int pathB, int cost) {
            this.pathA = pathA;
            this.pathB = pathB;
            this.cost = cost;
        }

        @Override
        public int compareTo(Path p) {
            if (this.cost < p.cost)
                return -1;
            else if (this.cost == p.cost)
                return 0;
            return 1;
        }
    }
}