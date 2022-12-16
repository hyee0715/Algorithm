import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int n;
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        while (true) {
            n = Integer.parseInt(br.readLine());

            if (n == 0) {
                break;
            }

            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        int winner;
        int mary = 0, john = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            winner = Integer.parseInt(st.nextToken());

            if (winner == 0) {
                mary++;
                continue;
            }

            john++;
        }

        bw.write("Mary won " + mary + " times and John won " + john + " times\n");
    }
}