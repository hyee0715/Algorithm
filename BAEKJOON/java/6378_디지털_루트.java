import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static String s;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        while (true) {
            s = br.readLine();

            if (s.equals("0")) break;

            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        int sum;

        while (true) {
            sum = 0;

            for (int i = 0; i < s.length(); i++) {
                sum += (s.charAt(i) - '0');
            }

            if (sum < 10) {
                break;
            }

            s = String.valueOf(sum);
        }

        bw.write(sum + "\n");
    }
}