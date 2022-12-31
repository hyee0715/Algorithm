import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        n = Integer.parseInt(br.readLine());

        int max = -1000001;
        int min = 1000001;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(st.nextToken());

            if (max < a) {
                max = a;
            }

            if (min > a) {
                min = a;
            }
        }

        bw.write(min + " " + max + "\n");
    }
}