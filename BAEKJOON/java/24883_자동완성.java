import java.io.*;
import java.util.HashMap;

public class Main {
    public static char c;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        c = br.readLine().charAt(0);
    }

    private static void solution() throws IOException {
        if (c == 'N' || c == 'n') {
            bw.write("Naver D2");
        } else {
            bw.write("Naver Whale");
        }
    }
}