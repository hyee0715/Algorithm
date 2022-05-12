import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int n, k, ans = 0;
    public static boolean[] visit = new boolean[10];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        dfs(0, 0);

        System.out.println(ans);
    }

    public static void dfs(int idx, int cnt) {
        if (cnt == k) {
            ans++;
        } else {
            for (int i = idx; i < n; i++) {
                if (visit[idx] == true) continue;
                visit[idx] = true;
                dfs(i, cnt + 1);
                visit[idx] = false;
            }
        }
    }
}

