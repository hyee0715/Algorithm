import java.io.*;
import java.util.*;

public class Main {
    public static int a, b, cnt = 0;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static String s;

    public static void main(String[] args) throws IOException {
        while (true) {
            s = br.readLine();

            if (s.equals("***")) break;

            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        for (int i = s.length() - 1; i >= 0; i--) {
            bw.write(s.charAt(i));
        }

        bw.write("\n");
    }
}