import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static int n, limit;
    public static List<Integer> nums = new ArrayList<>();
    public static List<Character> operations = new ArrayList<>();
    public static List<String> answer = new ArrayList<>();
    public static char[] oper = {' ', '+', '-'};

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            initialize();
            input();
            solution();

            bw.write("\n");
        }

        bw.flush();
        bw.close();
    }

    private static void initialize() throws IOException {
        nums.clear();
        operations.clear();
        answer.clear();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
    }

    private static void check() {
        StringBuilder cal = new StringBuilder();
        cal.append((char)(nums.get(0) + '0'));

        for (int i = 0; i < operations.size(); i++) {
            cal.append(operations.get(i));
            cal.append((char)(nums.get(i + 1) + '0'));
        }

        for (int i = 0; i < cal.length(); i++) {
            if (cal.charAt(i) == ' ') {
                cal.deleteCharAt(i);
            }
        }

        int sum = 0;
        StringBuilder temp = new StringBuilder();
        int idx = 0;

        for (int i = 0; i < cal.length(); i++) {
            if (cal.charAt(i) != '+' && cal.charAt(i) != '-') {
                temp.append(cal.charAt(i));
            }
            else {
                idx = i;
                break;
            }
        }

        sum += Integer.parseInt(temp.toString());
        temp.setLength(0);
        char op = cal.charAt(idx);

        for (int i = idx + 1; i < cal.length(); i++) {
            if (cal.charAt(i) == '+' || cal.charAt(i) == '-') {
                if (op == '+') {
                    sum += Integer.parseInt(temp.toString());
                    temp.setLength(0);
                    op = cal.charAt(i);
                }
                else if (op == '-') {
                    sum -= Integer.parseInt(temp.toString());
                    temp.setLength(0);
                    op = cal.charAt(i);
                }
            }
            else {
                temp.append(cal.charAt(i));
            }
        }

        if (temp.length() != 0) {
            if (op == '+') {
                sum += Integer.parseInt(temp.toString());
                temp.setLength(0);
            }
            else if (op == '-') {
                sum -= Integer.parseInt(temp.toString());
                temp.setLength(0);
            }
        }

        if (sum == 0) {
            temp.setLength(0);
            StringBuilder s = new StringBuilder();

            for (int i = 0; i < cal.length(); i++) {
                if (cal.charAt(i) == '+' || cal.charAt(i) == '-') {
                    temp.append(cal.charAt(i));
                    s.append(temp);
                    temp.setLength(0);
                }
                else {
                    if (temp.length() != 0) {
                        temp.append(" ");
                    }

                    temp.append(cal.charAt(i));
                }
            }

            if (temp.length() != 0) {
                s.append(temp);
                temp.setLength(0);
            }

            answer.add(s.toString());
        }
    }

    private static void dfs(int cnt) {
        if (cnt == limit) {
            check();

            return;
        }
        else {
          for (int i = 0; i < 3; i++) {
              operations.add(oper[i]);
              dfs(cnt + 1);
              operations.remove(operations.size() - 1);
          }
        }
    }

    private static void solution() throws IOException {
        for (int i = 1; i <= n; i++) {
            nums.add(i);
        }

        limit = nums.size() - 1;

        dfs(0);

        for (int i = 0; i < answer.size(); i++) {
            bw.write(answer.get(i) + "\n");
        }
    }
}