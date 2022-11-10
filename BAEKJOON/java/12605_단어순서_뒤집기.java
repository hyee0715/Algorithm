import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static String s;
    public static List<String> list = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            initialize();
            input();

            bw.write("Case #" + (i + 1) + ": ");
            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void initialize() {
        list.clear();
    }

    private static void input() throws IOException {
        s = br.readLine();
    }

    private static void solution() throws IOException {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                list.add(sb.toString());
                sb.setLength(0);
                continue;
            }

            if (s.charAt(i) != ' ') {
                sb.append(s.charAt(i));
            }
        }

        if (sb.length() != 0) {
            list.add(sb.toString());
            sb.setLength(0);
        }

        for (int i = list.size() - 1; i >= 0; i--) {
            bw.write(list.get(i));

            if (i != 0) {
                bw.write(" ");
            }
        }

        bw.write("\n");
    }
}