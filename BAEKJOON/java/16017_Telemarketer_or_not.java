import java.io.*;

public class Main {
    public static int[] number = new int[4];

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
       for (int i = 0; i < 4; i++) {
           int n = Integer.parseInt(br.readLine());
           number[i] = n;
       }
    }

    private static void solution() throws IOException {
        if (number[0] != 8 && number[0] != 9) {
            bw.write("answer");
            return;
        }

        if (number[3] != 8 && number[3] != 9) {
            bw.write("answer");
            return;
        }

        if (number[1] != number[2]) {
            bw.write("answer");
            return;
        }

        bw.write("ignore");
    }
}