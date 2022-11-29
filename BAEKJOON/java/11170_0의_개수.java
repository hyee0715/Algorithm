import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int a, b;

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

        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
    }

    private static void solution() throws IOException {
        int answer = 0;

        for (int i = a; i <= b; i++) {
            String s = String.valueOf(i);

            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == '0') {
                    answer++;
                }
            }
        }

        bw.write(answer + "\n");
    }
}