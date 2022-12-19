import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static int carPrice, optionCount, eachOptionCount, optionPrice;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        carPrice = Integer.parseInt(br.readLine());
        optionCount = Integer.parseInt(br.readLine());

        int sum = carPrice;

        StringTokenizer st;
        for (int i = 0; i < optionCount; i++) {
            st = new StringTokenizer(br.readLine());

            eachOptionCount = Integer.parseInt(st.nextToken());
            optionPrice = Integer.parseInt(st.nextToken());

            sum += (eachOptionCount * optionPrice);
        }

        bw.write(sum + "\n");
    }
}