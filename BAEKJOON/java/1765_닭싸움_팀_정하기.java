import java.io.*;
import java.util.*;

public class Main {
    public static int n, m;
    public static int[] parent;
    public static List<int[]> friends = new ArrayList<>();
    public static Map<Integer, List<Integer>> enemy = new HashMap<>();
    public static int answer = 0;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            char c = st.nextToken().charAt(0);
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (c == 'F') {
                friends.add(new int[] {a, b});
                friends.add(new int[] {b, a});
                continue;
            }

            if (!enemy.containsKey(a)) {
                enemy.put(a, new ArrayList<>());
            }
            enemy.get(a).add(b);

            if (!enemy.containsKey(b)) {
                enemy.put(b, new ArrayList<>());
            }
            enemy.get(b).add(a);
        }
    }

    private static int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }

        parent[x] = findParent(parent[x]);
        return parent[x];
    }

    private static boolean sameParent(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x == y) {
            return true;
        }

        return false;
    }

    private static void unionParent(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x < y) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
        }
    }

    private static void solution() throws IOException {
        parent = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < friends.size(); i++) {
            int[] friendArr = friends.get(i);
            if (!sameParent(friendArr[0], friendArr[1])) {
                unionParent(friendArr[0], friendArr[1]);
            }
        }

        for (int key : enemy.keySet()) {
            List<Integer> enemyList = enemy.get(key);

            for (int i = 0; i < enemyList.size() - 1; i++) {
                for (int j = i + 1; j < enemyList.size(); j++) {
                    if (!sameParent(enemyList.get(i), enemyList.get(j))) {
                        unionParent(enemyList.get(i), enemyList.get(j));
                    }
                }
            }
        }

        Map<Integer, Integer> relationCount = new HashMap<>();

        for (int i = 1; i < parent.length; i++) {
            parent[i] = findParent(parent[i]);

            relationCount.put(parent[i], relationCount.getOrDefault(parent[i], 0) + 1);
        }

        answer = relationCount.size();

        bw.write(String.valueOf(answer));
    }
}