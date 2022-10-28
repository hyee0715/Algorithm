import java.io.*;

public class Main {
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
        int n = Integer.parseInt(br.readLine());
        s = br.readLine();
    }

    private static void solution() throws IOException {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'J' || s.charAt(i) == 'A' || s.charAt(i) == 'V') {
                continue;
            }

            sb.append(s.charAt(i));
        }

        if (sb.toString().isEmpty()) {
            bw.write("nojava");
        } else {
            bw.write(sb.toString());
        }
    }
}