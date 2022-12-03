import java.io.*;

public class Main {
    public static int n;
    public static String name;

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
        name = br.readLine();
    }

    private static void solution() throws IOException {
        int score = 0;

        for (int i = 0; i < name.length(); i++) {
            score += (name.charAt(i) - 'A' + 1);
        }

        bw.write(String.valueOf(score));
    }
}