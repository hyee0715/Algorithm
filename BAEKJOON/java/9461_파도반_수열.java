import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static int n, tc;
    public static long[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        tc = Integer.parseInt(br.readLine());

        for (int t = 0; t < tc; t++) {
            n = Integer.parseInt(br.readLine());
            dp = new long[n + 10];

            dp[1] = 1;
            dp[2] = 1;
            dp[3] = 1;
            dp[4] = 2;
            dp[5] = 2;
            dp[6] = 3;
            dp[7] = 4;

            for (int i = 8; i <= n; i++) {
                dp[i] = dp[i - 5] + dp[i - 1];
            }

            System.out.println(dp[n]);
        }
    }
}