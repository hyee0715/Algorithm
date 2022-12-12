import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int a_cnt = 0, b_cnt = 0;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        solution();

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (a > b) {
                a_cnt++;
                continue;
            }

            if (a < b) {
                b_cnt++;
            }
        }

        bw.write(a_cnt + " " + b_cnt);
    }
}