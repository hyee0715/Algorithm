import java.io.*;

public class Main {
    public static int sum;
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
       sum = Integer.parseInt(br.readLine());
    }

    private static void solution() throws IOException {
        int price;

        for (int i = 0; i < 9; i++) {
            price = Integer.parseInt(br.readLine());
            sum -= price;
        }

        bw.write(String.valueOf(sum));
    }
}