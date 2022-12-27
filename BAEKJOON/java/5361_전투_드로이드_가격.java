import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static double[] prices = {350.34, 230.90, 190.55, 125.30, 180.90};
    public static List<Double> list = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine())
;
        for (int i = 0; i < tc; i++) {
            input();
            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        list.clear();

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 5; i++) {
            Double n = Double.parseDouble(st.nextToken());
            list.add(n);
        }
    }

    private static void solution() throws IOException {
        double sum = 0;

        for (int i = 0; i < list.size(); i++) {
            sum += (prices[i] * list.get(i));
        }

        String format = String.format("$%.2f\n", sum);
        bw.write(format);
    }
}