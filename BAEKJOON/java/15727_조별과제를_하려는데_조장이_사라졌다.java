import java.io.*;

public class Main {
    public static int l;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        l = Integer.parseInt(br.readLine());
    }

    private static void solution() throws IOException {
        if (l < 5) {
            bw.write("1");
            return;
        }

        int t = (l / 5);

        if (l % 5 != 0) {
            t++;
        }

        bw.write(String.valueOf(t));
    }
}