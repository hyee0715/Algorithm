import java.io.*;
import java.util.*;

public class Main {
    public static int n, k, answer = 0;
    public static List<Integer> candy = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            initialize();
            input();
            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void initialize() throws IOException {
        answer = 0;
        candy.clear();
    }

    private static void input() throws IOException {
        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(st.nextToken());
            candy.add(a);
        }
    }

    private static void solution() throws IOException {
        for (int i = 0; i < candy.size(); i++) {
            answer += (candy.get(i) / k);
        }

        bw.write(answer + "\n");
    }
}