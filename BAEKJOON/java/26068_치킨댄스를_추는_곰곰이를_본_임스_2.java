import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static int n, answer = 0;
    public static List<String> list = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            list.add(s);
        }
    }

    private static void solution() throws IOException {
        StringBuilder sb;

        for (int i = 0; i < list.size(); i++) {
            sb = new StringBuilder(list.get(i));
            sb.delete(0, 2);

            int day = Integer.parseInt(sb.toString());
            if (day <= 90) {
                answer++;
            }
        }

        bw.write(String.valueOf(answer));
    }
}