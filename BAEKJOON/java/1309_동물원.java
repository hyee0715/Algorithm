import java.io.*;

public class Main {
    public static int n;
    public static int[] dp = new int[100001];

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
    }

    private static void solution() throws IOException {
        dp[1] = 3;
        dp[2] = 7;

        if (n <= 2) {
            bw.write(String.valueOf(dp[n]));

            return;
        }

        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 2] + 2 * dp[i - 1]) % 9901;
        }

        bw.write(String.valueOf(dp[n]));
    }
}