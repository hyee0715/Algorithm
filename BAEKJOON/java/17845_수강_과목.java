import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n, k;
    public static int[] importance, time;

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
        k = Integer.parseInt(st.nextToken());

        importance = new int[k + 1];
        time = new int[k + 1];

        for (int i = 1; i <= k; i++) {
            st = new StringTokenizer(br.readLine());

            importance[i] = Integer.parseInt(st.nextToken());
            time[i] = Integer.parseInt(st.nextToken());
        }
    }

    private static void solution() throws IOException {
        int[][] dp = new int[k + 1][n + 1];

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                if (time[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - time[i]] + importance[i]);
                }
            }
        }

        bw.write(String.valueOf(dp[k][n]));
    }
}