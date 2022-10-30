import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static List<List<Character>> map = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            List<Character> temp = new ArrayList<>();

            for (int j = 0; j < s.length(); j++) {
                temp.add(s.charAt(j));
            }

            map.add(temp);
        }
    }

    private static void solution() throws IOException {
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map.get(i).size(); j++) {
                if (map.get(i).get(j) != map.get(j).get(i)) {
                    System.out.println("NO");
                    return;
                }
            }
        }

        System.out.println("YES");
    }
}