import java.io.*;
import java.util.*;

public class Main {
    public static int n, max_day = -1, answer = 0;
    public static Map<Integer, ArrayList<Integer>> map = new HashMap<>();
    public static List<Assignment> list = new ArrayList<>();
    public static List<Integer> task = new ArrayList<>();

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

        StringTokenizer st;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (max_day < a) {
                max_day = a;
            }

            if (map.containsKey(a)) {
                map.get(a).add(b);
                continue;
            }

            if (!map.containsKey(a)) {
                map.put(a, new ArrayList<>(Arrays.asList(b)));
            }
        }
    }

    private static void solution() throws IOException {
        while (max_day > 0) {
            if (map.containsKey(max_day)) {
                for (int i = 0; i < map.get(max_day).size(); i++) {
                    Assignment assignment = new Assignment(map.get(max_day).get(i), max_day);

                    list.add(assignment);
                }
            }

            Collections.sort(list);

            if (list.isEmpty()) {
                max_day--;
                continue;
            }

            task.add(list.get(0).score);

            list.remove(0);

            max_day--;
        }

        task.stream().forEach(x -> answer += x);

        System.out.println(answer);
    }
}

class Assignment implements Comparable<Assignment> {
    int score;
    int RemainingDays;

    public Assignment(int score, int remainingDays) {
        this.score = score;
        RemainingDays = remainingDays;
    }

    @Override
    public int compareTo(Assignment o) {
        if (this.score < o.score) {
            return 1;
        }

        if (this.score == o.score) {
            return 0;
        }

        return -1;
    }
}
