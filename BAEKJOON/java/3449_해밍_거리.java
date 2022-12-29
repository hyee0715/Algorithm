import java.io.*;

public class Main {
    public static String a, b;

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
        a = br.readLine();
        b = br.readLine();
    }

    private static void solution() throws IOException {
        int answer = 0;

        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                answer++;
            }
        }

        bw.write("Hamming distance is " + answer + ".\n");
    }
}