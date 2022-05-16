import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static int n, m, v;
    public static boolean[] visit;
    public static List<Integer>[] node;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        v = Integer.parseInt(st.nextToken());

        visit = new boolean[n + 1];
        node = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            node[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            int a, b;
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            node[a].add(b);
            node[b].add(a);
        }

        for (int i = 1; i <= n; i++) {
            Collections.sort(node[i]);
        }

        Arrays.fill(visit, false);
        dfs(v);
        System.out.println();

        Arrays.fill(visit, false);
        bfs(v);
    }

    public static void dfs(int x) {
        if (visit[x] == true) return;
        visit[x] = true;
        System.out.print(x + " ");

        for (int i = 0; i < node[x].size(); i++) {
            int nx = node[x].get(i);

            if (visit[nx] == false)
                dfs(nx);
        }
    }

    public static void bfs(int a) {
        Queue<Integer> q = new LinkedList<>();
        q.add(a);
        visit[a] = true;

        while (!q.isEmpty()) {
            int x = q.peek();
            q.poll();
            System.out.print(x + " ");

            for (int i = 0; i < node[x].size(); i++) {
                int nx = node[x].get(i);

                if (visit[nx] == false) {
                    q.add(nx);
                    visit[nx] = true;
                }
            }
        }
    }
}
