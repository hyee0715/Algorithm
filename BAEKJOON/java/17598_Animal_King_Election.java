import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static int lion = 0, tiger = 0;
    public static List<String> animal = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        for (int i = 0; i < 9; i++) {
            String s = br.readLine();

            animal.add(s);
        }
    }

    private static void solution() throws IOException {
        for (int i = 0; i < animal.size(); i++) {
            if (animal.get(i).equals("Lion")) {
                lion++;
                continue;
            }

            tiger++;
        }

        if (lion > tiger) {
            bw.write("Lion");
            return;
        }

        bw.write("Tiger");
    }
}