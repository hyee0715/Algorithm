import java.io.*;
import java.util.*;

public class Main {
    public static int cnt = 0;
    public static String s;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        s = br.readLine();
    }

    private static void solution() throws IOException {
        while (s.length() > 1) {
            int sum = 1;
            cnt++;

            for (int i = 0; i < s.length(); i++) {
                sum *= (s.charAt(i) - '0');
            }

            s = String.valueOf(sum);
        }

        bw.write(String.valueOf(cnt));
    }
}