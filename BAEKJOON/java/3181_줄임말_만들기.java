import java.io.*;
import java.util.*;

public class Main {
    public static String s;
    public static StringBuilder answer = new StringBuilder();
    public static Set<String> set = new HashSet<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        s = br.readLine();
    }

    private static void solution() throws IOException {
        String[] ignore = { "i", "pa", "te", "ni", "niti", "a", "ali",  "nego", "no", "ili" };

        set.addAll(Arrays.asList(ignore));

        String[] words = s.split(" ");

        for (int i = 0; i < words.length; i++) {
            if (i == 0 || !set.contains(words[i])) {
                answer.append(words[i].toUpperCase().charAt(0));
            }
        }

        bw.write(answer.toString());
    }
}