import java.io.*;

public class Main {
    public static int month, day;
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        month = Integer.parseInt(br.readLine());
        day = Integer.parseInt(br.readLine());
    }

    private static void solution() throws IOException {
        if (month > 2) {
            bw.write("After");
            return;
        }

        if (month == 2) {
            if (day == 18) {
                bw.write("Special");
                return;
            }

            if (day > 18) {
                bw.write("After");
                return;
            }
        }

        bw.write("Before");
    }
}