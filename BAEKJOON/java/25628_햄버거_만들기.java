import java.io.*;
import java.util.*;

public class Main {
    public static int a, b, cnt = 0;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
    }

    private static void solution() throws IOException {
        while (a >= 2 && b >= 1) {
            cnt++;
            a -= 2;
            b -= 1;
        }

        bw.write(cnt + "");
    }
}