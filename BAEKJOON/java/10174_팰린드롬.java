import java.io.*;

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
        s = s.toLowerCase();

        StringBuilder sb = new StringBuilder(s);
        String rev = sb.reverse().toString();

        if (rev.equals(s)) {
            bw.write("Yes\n");
            return;
        }

        bw.write("No\n");
    }
}