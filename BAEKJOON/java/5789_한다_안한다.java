import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static String s;

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
        s = br.readLine();
    }

    private static void solution() throws IOException {
       int mid = (s.length() / 2) - 1;

       if (s.charAt(mid) == s.charAt(mid + 1)) {
           bw.write("Do-it\n");
           return;
       }

       bw.write("Do-it-Not\n");
    }
}