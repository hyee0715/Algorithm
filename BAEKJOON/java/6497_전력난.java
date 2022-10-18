import java.io.*;
import java.util.*;


public class Main {
    public static int m, n, sum, total;
    public static List<Path> path = new ArrayList<>();
    public static int[] parent = new int[200001];

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        while (true) {
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());

            if (m == 0 && n == 0)
                break;

            initialize();
            input();
            solution();
        }

        bw.flush();
        bw.close();
    }

    static class Path implements Comparable<Path> {
        int x;
        int y;
        int distance;

        public Path(int x, int y, int distance) {
            this.x = x;
            this.y = y;
            this.distance = distance;
        }

        @Override
        public int compareTo(Path path) {
            if (path.distance < distance) {
                return 1;
            } else if (path.distance > distance) {
                return -1;
            }

            return 0;
        }
    }

    private static void initialize() {
        sum = 0;
        total = 0;
        path.clear();

        for (int i = 1; i <= m; i++) {
            parent[i] = i;
        }
    }

    private static void input() throws IOException {
        int x, y, z;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            z = Integer.parseInt(st.nextToken());

            Path p = new Path(x, y, z);
            path.add(p);
            total += z;
        }
    }

    private static int find_parent(int x) {
        if (parent[x] == x) return x;
        else return parent[x] = find_parent(parent[x]);
    }

    private static boolean same_parent(int x, int y) {
        x = find_parent(x);
        y = find_parent(y);

        if (x == y)
            return true;
        else
            return false;
    }

    private static void union_parent(int x, int y) {
        x = find_parent(x);
        y = find_parent(y);

        if (x < y)
            parent[y] = x;
        else
            parent[x] = y;
    }

    private static void solution() throws IOException {
        Collections.sort(path);

        for (int i = 0; i < n; i++) {
            if (same_parent(path.get(i).x, path.get(i).y) == false) {
                union_parent(path.get(i).x, path.get(i).y);
                sum = sum + path.get(i).distance;
            }
        }

        bw.write(total - sum + "\n");
    }
}