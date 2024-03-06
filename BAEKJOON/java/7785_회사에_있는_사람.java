import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int r, c, t;
    public static int[][] map;
    public static int[] dx = new int[]{0, 0, 1, -1};
    public static int[] dy = new int[]{1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        solution();

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
       Set<String> st = new HashSet<>();

       int n = Integer.parseInt(br.readLine());

       for (int i = 0; i < n; i++) {
           String[] str = br.readLine().split(" ");

           if (str[1].equals("enter")) {
               st.add(str[0]);
           } else {
               st.remove(str[0]);
           }
       }

        List<String> names = new ArrayList<>();

       for (String name : st) {
           names.add(name);
       }

       Collections.sort(names, Collections.reverseOrder());

       for (String name : names) {
           bw.write(name + "\n");
       }
    }
}