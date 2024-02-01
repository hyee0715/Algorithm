import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static Map<Integer, Integer> weight = new HashMap<>(); //회원번호, 무게
    public static Map<Integer, List<Integer>> friends = new HashMap<>(); //회원번호, 친구목록
    public static int n, m; //n:회원, m:친분관계
    public static List<Integer> person = new ArrayList<>();
    public static List<int[]> link = new ArrayList<>();

    public static int answer = 0;

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(st.nextToken());
            person.add(num);
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            link.add(new int[]{a, b});
        }
    }

    private static void init() {
        for (int i = 0; i < person.size(); i++) {
            weight.put(i + 1, person.get(i));
        }

        for (int i = 0; i < link.size(); i++) {
            int[] cur = link.get(i);
            int a = cur[0];
            int b = cur[1];

            if (!friends.containsKey(a)) {
                friends.put(a, new ArrayList<>());
            }

            friends.get(a).add(b);

            if (!friends.containsKey(b)) {
                friends.put(b, new ArrayList<>());
            }

            friends.get(b).add(a);
        }

        for (int i = 1; i <= n; i++) {
            if (!friends.containsKey(i)) {
                friends.put(i, new ArrayList<>());
            }
        }
    }

    private static void solution() throws IOException {
        init();

        for (int key : friends.keySet()) {
            List<Integer> list = friends.get(key);

            if (list.isEmpty()) {
                answer++;
                continue;
            }

            boolean flag = false;
            int personNum = key;
            int personWeight = weight.get(personNum);

            for (int i = 0; i < list.size(); i++) {
                int friendNum = list.get(i);
                int friendWeight = weight.get(friendNum);

                if (personWeight <= friendWeight) {
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                answer++;
            }
        }

        bw.write(String.valueOf(answer));
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }
}
