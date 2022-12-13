import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n, k;
    public static int[] weight, value;

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

        weight = new int[n + 1];
        value = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            weight[i] = Integer.parseInt(st.nextToken());
            value[i] = Integer.parseInt(st.nextToken());
        }
    }

    private static void solution() throws IOException {
        int[][] dp = new int[n + 1][k + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (weight[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                }
            }
        }

        bw.write(String.valueOf(dp[n][k]));
    }
}