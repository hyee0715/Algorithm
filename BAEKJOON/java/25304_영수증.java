import java.io.*;
import java.util.*;

public class Main {
    public static int x, n, a, b, sum = 0;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        x = Integer.parseInt(br.readLine());
        n = Integer.parseInt(br.readLine());
    }

    private static void solution() throws IOException {
        StringTokenizer st;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            sum += (a * b);
        }

        if (sum == x)
            bw.write("Yes");
        else
            bw.write("No");
    }
}