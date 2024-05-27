import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int n, maxNum, minNum;
    public static int[] nums, ops;
    public static List<Character> operators, list;
    public static boolean[] visit;

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        nums = new int[n];
        ops = new int[4];

        String[] st = br.readLine().split(" ");

        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st[i]);
        }

        st = br.readLine().split(" ");

        for (int i = 0; i < 4; i++) {
            ops[i] = Integer.parseInt(st[i]);
        }
    }
    private static void solution() throws IOException {
        operators = makeOps();
        visit = new boolean[operators.size()];
        list = new ArrayList<>();

        minNum = 1000000001;
        maxNum = -1000000001;

        //순열
        dfs(0);

        bw.write(String.valueOf(maxNum) + "\n" + String.valueOf(minNum));
    }

    private static List<Character> makeOps() {
        List<Character> ret = new ArrayList<>();
        char[] op = {'+', '-', '*', '/'};

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < ops[i]; j++) {
                ret.add(op[i]);
            }
        }

        return ret;
    }

    private static void dfs(int cnt) {
        if (cnt == n - 1) {
            int result = calculate();

            minNum = Math.min(minNum, result);
            maxNum = Math.max(maxNum, result);

            return;
        }

        for (int i = 0; i < operators.size(); i++) {
            if (visit[i]) continue;
            visit[i] = true;
            list.add(operators.get(i));
            dfs(cnt + 1);
            visit[i] = false;
            list.remove(list.size() - 1);
        }
    }

    private static int calculate() {
        List<Integer> calNums = new ArrayList<>();
        List<Character> calOps = new ArrayList<>();

        int idx = 0;
        calNums.add(nums[idx++]);

        //곱하기, 나누기 먼저 계산
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) != '*' && list.get(i) != '/') {
                calOps.add(list.get(i));
                calNums.add(nums[idx++]);
            } else {
                int cur = calNums.get(calNums.size() - 1);
                calNums.remove(calNums.size() - 1);

                if (list.get(i) == '*') {
                    calNums.add(cur * nums[idx++]);
                } else {
                    calNums.add(cur / nums[idx++]);
                }
            }
        }

        //더하기, 빼기 계산
        idx = 0;
        int result = calNums.get(idx++);

        for (int i = 0; i < calOps.size(); i++) {
            if (calOps.get(i) == '+') {
                result += calNums.get(idx++);
            } else {
                result -= calNums.get(idx++);
            }
        }

        return result;
    }
}