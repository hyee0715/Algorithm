import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class Main {
    public static int tc;
    public static List<Integer> list = new ArrayList<>(), even = new ArrayList<>();
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        tc = Integer.parseInt(st.nextToken());

        for (int i = 0; i < tc; i++) {
            input();
            solution();
        }
    }

    private static void input()  throws IOException {
        list.clear();

        int n;
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 7; i++) {
            n = Integer.parseInt(st.nextToken());
            list.add(n);
        }
    }

    private static void solution() {
        int min = 101;
        int sum = 0;

        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) % 2 == 0) {
                if (min > list.get(i)) {
                    min = list.get(i);
                }

                sum += list.get(i);
            }
        }

        System.out.println(sum + " " + min);
    }
}