import java.io.*;

public class Main {
    public static String s, t;

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
        t = br.readLine();
    }

    private static void check(String s, String t) {
        if (s.equals(t)) {
            System.out.println(1);
            System.exit(0);
        }

        if (s.length() == t.length()) {
            return;
        }

        if (t.charAt(t.length() - 1) == 'A') {
            StringBuilder tempT = new StringBuilder(t);
            check(s, tempT.deleteCharAt(tempT.length() - 1).toString());
        }

        if (t.charAt(0) == 'B') {
            StringBuilder tempT = new StringBuilder(t);
            tempT.deleteCharAt(0);
            tempT.reverse();

            check(s, tempT.toString());
        }
    }

    private static void solution() throws IOException {
        check(s, t);

        bw.write(String.valueOf(0));
    }
}