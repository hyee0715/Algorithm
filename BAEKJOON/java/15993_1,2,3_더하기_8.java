import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static long[][] dp = new long[100001][3]; // [3]은 1~2만 사용. (1 == 홀수, 2 == 짝수)

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        solution();

        int tc = Integer.parseInt(st.nextToken());

        for (int i = 0; i < tc; i++) {
            st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());

            System.out.println(dp[n][1] + " " + dp[n][2]);
        }
    }

    //dp[a][b] = c -> 정수 a를 1, 2, 3의 합으로 나타낼 때, 사용한 수의 개수가 홀수(b == 1)이거나, 짝수(b == 2)인 경우의 수는 c개이다.
    public static void solution() {
        dp[1][1] = 1;
        dp[1][2] = 0;
        dp[2][1] = 1;
        dp[2][2] = 1;
        dp[3][1] = 2;
        dp[3][2] = 2;

        for (int i = 4; i <= 100000; i++) {
            // 홀수 개수
            dp[i][1] = (dp[i - 1][2] + dp[i - 2][2] + dp[i - 3][2]) % 1000000009;

            // 짝수 개수
            dp[i][2] = (dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]) % 1000000009;
        }
    }
}
