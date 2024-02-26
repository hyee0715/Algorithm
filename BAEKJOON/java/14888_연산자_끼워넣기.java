import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int n;
    public static int[] nums;
    public static int[] ops = new int[4];
    public static int maxNum = -1000000001;
    public static int minNum = 1000000001;

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());

        nums = new int[n];

        String[] str = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(str[i]);
        }

        str = br.readLine().split(" ");
        for (int i = 0; i < 4; i++) {
            ops[i] = Integer.parseInt(str[i]);
        }
    }

    private static void solution() throws IOException {
        List<Character> operators = getOperators();

        boolean[] visit = new boolean[operators.size()];
        List<Character> list = new ArrayList<>();

        dfs(0, operators, visit, list);

        bw.write(String.valueOf(maxNum) + "\n" + String.valueOf(minNum));
    }

    private static void dfs(int cnt, List<Character> operators, boolean[] visit, List<Character> list) {
        if (cnt == operators.size()) {
            maxNum = Math.max(maxNum, calculate(list));
            minNum = Math.min(minNum, calculate(list));
        } else {
            for (int i = 0; i < operators.size(); i++) {
                if (visit[i] == true) continue;
                visit[i] = true;
                list.add(operators.get(i));
                dfs(cnt + 1, operators, visit, list);
                visit[i] = false;
                list.remove(list.size() - 1);
            }
        }
    }

    private static int calculate(List<Character> list) {
        int result = nums[0];

        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) == '+') {
                result += nums[i + 1];
            } else if (list.get(i) == '-') {
                result -= nums[i + 1];
            } else if (list.get(i) == '*') {
                result *= nums[i + 1];
            } else {
                if (result < 0) {
                    result *= -1;
                    result /= nums[i + 1];
                    result *= -1;
                } else {
                    result /= nums[i + 1];
                }
            }
        }

        return result;
    }

    private static List<Character> getOperators() {
        List<Character> ret = new ArrayList<>();

        for (int i = 0; i < ops[0]; i++) {
            ret.add('+');
        }

        for (int i = 0; i < ops[1]; i++) {
            ret.add('-');
        }

        for (int i = 0; i < ops[2]; i++) {
            ret.add('*');
        }

        for (int i = 0; i < ops[3]; i++) {
            ret.add('/');
        }

        return ret;
    }
}