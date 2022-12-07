import java.io.*;

public class Main {
    public static int limit, speed;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        limit = Integer.parseInt(br.readLine());
        speed = Integer.parseInt(br.readLine());
    }

    private static void solution() throws IOException {
        if (speed <= limit) {
            bw.write("Congratulations, you are within the speed limit!");
            return;
        }

        if (speed - limit >= 1 && speed - limit <= 20) {
            bw.write("You are speeding and your fine is $100.");
            return;
        }

        if (speed - limit >= 21 && speed - limit <= 30) {
            bw.write("You are speeding and your fine is $270.");
            return;
        }

        bw.write("You are speeding and your fine is $500.");
    }
}