import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static char c;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            input();
            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        c = st.nextToken().charAt(0);
    }

    private static void solution() throws IOException {
        for (int i = 0; i < n; i++) {
            bw.write(c);
        }

        bw.write("\n");
    }
}