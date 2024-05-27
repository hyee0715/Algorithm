import java.awt.*;
import java.io.*;
import java.util.*;
import java.util.List;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int n;
    public static int[] arr, dp;

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());

        arr = new int[n + 1];

        String[] st = br.readLine().split(" ");

        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(st[i - 1]);
        }
    }
    private static void solution() throws IOException {
        dp = new int[n + 1];
        dp[1] = arr[1];

        for (int i = 2; i <= n; i++) {
            dp[i] = Math.max(dp[i], arr[i]);

            for (int j = 0; j < i; j++) {
                dp[i] = Math.max(dp[i], dp[i - j] + arr[j]);
            }
        }

        bw.write(String.valueOf(dp[n]));
    }
}