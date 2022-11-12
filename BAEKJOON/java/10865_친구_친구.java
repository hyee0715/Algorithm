import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n, m;
    public static int[] friends = new int[100001];

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

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            friends[a]++;
            friends[b]++;
        }
    }

    private static void solution() throws IOException {
       for (int i = 1; i <= n; i++) {
           bw.write(friends[i] + "\n");
       }
    }
}