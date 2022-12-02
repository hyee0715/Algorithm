import java.io.*;
import java.util.ArrayList;

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
        StringBuilder revS = new StringBuilder(s);
        revS.reverse();

        int sum = Integer.parseInt(s) + Integer.parseInt(revS.toString());

        String strSum = String.valueOf(sum);
        StringBuilder revStrSum = new StringBuilder(strSum);
        revStrSum.reverse();

        if (strSum.equals(revStrSum.toString())) {
            bw.write("YES\n");
            return;
        }

        bw.write("NO\n");
    }
}