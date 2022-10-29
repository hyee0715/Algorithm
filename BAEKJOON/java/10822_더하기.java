import java.io.*;

public class Main {
    public static String s;
    public static int answer = 0;

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
    }

    private static void solution() throws IOException {
        String[] str = s.split(",");

        for (int i = 0; i < str.length; i++) {
            answer += Integer.parseInt(str[i]);
        }

        bw.write(String.valueOf(answer));
    }
}
