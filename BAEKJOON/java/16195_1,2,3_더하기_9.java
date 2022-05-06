import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int n, m;
    public static long[][] dp = new long[1001][1001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        solution();

        int tc = Integer.parseInt(st.nextToken());

        for (int i = 0; i < tc; i++) {
            st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            find_answer();
        }
    }

    public static void solution() {
        dp[1][1] = 1;
        dp[2][1] = 1;
        dp[2][2] = 1;
        dp[3][1] = 1;
        dp[3][2] = 2;
        dp[3][3] = 1;

        for (int i = 4; i < 1001; i++) {
            for (int j = 2; j <= i; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % 1000000009;
            }
        }
    }

    public static void find_answer() {
        long answer = 0;
        for (int i = 1; i <= m; i++) {
            answer += dp[n][i];
            answer = (answer) % 1000000009;
        }

        System.out.println(answer);
    }
}
