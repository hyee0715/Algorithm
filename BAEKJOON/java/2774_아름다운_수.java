import java.io.*;
import java.util.*;

public class Main {
    public static int answer = 0;
    public static String s;
    public static HashMap<Character, Integer> hashMap = new HashMap<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            initialize();
            input();
            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void initialize() throws IOException {
        hashMap.clear();
    }

    private static void input() throws IOException {
        s = br.readLine();
    }

    private static void solution() throws IOException {
        for (int i = 0; i < s.length(); i++) {
            hashMap.put(s.charAt(i), hashMap.getOrDefault(s.charAt(i), 0) + 1);
        }

        answer = hashMap.size();

        bw.write(answer + "\n");

        List<Integer> list = new ArrayList<>();
        list.add(1);

    }
}