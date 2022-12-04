import java.io.*;

public class Main {
    public static double current_temp, temperature;
    public static boolean start = false;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        while (true) {
            current_temp = Double.parseDouble(br.readLine());

            if (current_temp == 999) {
                break;
            }

            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        if (!start) {
            start = true;
            temperature = current_temp;
            return;
        }

        String result = String.format("%.2f", current_temp - temperature);
        bw.write(result + "\n");
        temperature = current_temp;
    }
}