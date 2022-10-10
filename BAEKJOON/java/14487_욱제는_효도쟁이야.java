import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;


public class Main {
    public static List<Integer> list = new ArrayList<>();
    public static int n, answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        int a;
        for (int i = 0; i < n; i++) {
            a = Integer.parseInt(st.nextToken());
            list.add(a);
        }

        Collections.sort(list);

        for (int i = 0; i < list.size() - 1; i++) {
            answer += list.get(i);
        }

        System.out.println(answer);
    }
}