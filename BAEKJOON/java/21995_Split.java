import java.io.*;
import java.util.*;

public class Main {
    public static String s;
    public static List<Integer> nums = new ArrayList<>();
    public static List<Integer> answer = new ArrayList<>();

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
        StringBuilder a = new StringBuilder();
        StringBuilder b = new StringBuilder();

        for (int i = 0; i < s.length() / 2; i++) {
            a.append(s.charAt(i));
        }

        for (int i = s.length() / 2; i < s.length(); i++) {
            b.append(s.charAt(i));
        }

        bw.write(a.toString() + " " + b.toString());
    }
}