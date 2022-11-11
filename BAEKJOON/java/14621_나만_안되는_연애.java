import java.io.*;
import java.util.*;

public class Main {
    public static int n, m, path_sum = 0;
    public static List<String> gender = new ArrayList<>();
    public static List<Path> path = new ArrayList<>();
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

        st = new StringTokenizer(br.readLine());

        gender.add("N");
        for (int i = 0; i < n; i++) {
            String s = st.nextToken();
            gender.add(s);
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            Path p = new Path(a, b, cost);
            path.add(p);
        }
    }

    private static void solution() throws IOException {
        parent.add(-1);

        for (int i = 1; i <= n; i++) {
            parent.add(i);
        }

        Collections.sort(path);

        for (int i = 0; i < path.size(); i++) {
            int x = path.get(i).pathA;
            int y = path.get(i).pathB;

            if (!sameParent(x, y) && !gender.get(x).equals(gender.get(y))) {
                unionParent(x, y);

                path_sum += path.get(i).cost;
            }
        }

        if (allConnected()) {
            bw.write(String.valueOf(path_sum));
            return;
        }

        bw.write(String.valueOf(-1));
    }

    private static boolean allConnected() {
        for (int i = 1; i < parent.size() - 1; i++) {
            if (!sameParent(parent.get(i), parent.get(i + 1)))
                return false;
        }

        return true;
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