import java.io.*;
import java.util.*;

public class Main {
    public static String a, b;
    public static long answer = 0;

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

        a = st.nextToken();
        b = st.nextToken();
    }

    private static void solution() throws IOException {
        for (int i = 0; i < a.length(); i++) {
            for (int j = 0; j < b.length(); j++) {
                answer += ((a.charAt(i) - '0') * (b.charAt(j) - '0'));
            }
        }

        bw.write(String.valueOf(answer));
    }
}