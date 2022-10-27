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
       s = br.readLine();
    }

    private static void solution() throws IOException {
        String[] arr = s.split(",");

        bw.write(String.valueOf(arr.length));
    }
}