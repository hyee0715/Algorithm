import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int a, b, c;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
    }

    private static void solution() throws IOException {
        if (a + b == c || b + c == a || a + c == b) {
            bw.write(String.valueOf(1));
            return;
        }

        if (a * b == c || b * c == a || a * c == b) {
            bw.write(String.valueOf(2));
            return;
        }

        bw.write(String.valueOf(3));
    }
}