import java.io.*;
import java.util.*;

public class Main {
    public static String a, b;
    public static int n, a_score = 0, b_score = 0;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;

    public static void main(String[] args) throws IOException {

        while (true) {
            st = new StringTokenizer(br.readLine());

            a = st.nextToken();
            b = st.nextToken();

            if (a.equals("#") && b.equals("#")) break;

            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        n = Integer.parseInt(br.readLine());

        a_score = 0;
        b_score = 0;

        String c, d;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            c = st.nextToken();
            d = st.nextToken();

            if (c.equals(d)) {
                a_score++;
            } else {
                b_score++;
            }
        }

        bw.write(a + " " + a_score + " " + b + " " + b_score + "\n");
    }
}