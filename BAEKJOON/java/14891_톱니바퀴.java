import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static String a, b, c, d;
    public static int k;
    public static List<int[]> proceed = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                a = br.readLine();
            } else if (i == 1) {
                b = br.readLine();
            } else if (i == 2) {
                c = br.readLine();
            } else {
                d = br.readLine();
            }
        }

        k = Integer.parseInt(br.readLine());

        for (int i = 0; i < k; i++) {
            String[] str = br.readLine().split(" ");

            proceed.add(new int[]{Integer.parseInt(str[0]), Integer.parseInt(str[1])});
        }
    }

    private static void solution() throws IOException {
        Queue<int[]> executeQueue = new LinkedList<>();

        int right = 2, left = 6;

        for (int i = 0; i < proceed.size(); i++) {
            int[] cur = proceed.get(i);

            int clockNum = cur[0];
            int direction = cur[1];

            if (clockNum == 1) {
                executeQueue.add(new int[]{ 1, direction });

                if (a.charAt(right) != b.charAt(left)) {
                    int reverseDirection = getReverse(direction);
                    executeQueue.add(new int[]{ 2, reverseDirection });

                    if (b.charAt(right) != c.charAt(left)) {
                        reverseDirection = getReverse(reverseDirection);
                        executeQueue.add(new int[]{ 3, reverseDirection });

                        if (c.charAt(right) != d.charAt(left)) {
                            reverseDirection = getReverse(reverseDirection);
                            executeQueue.add(new int[]{ 4, reverseDirection });
                        }
                    }
                }
            }
            else if (clockNum == 2) {
                executeQueue.add(new int[]{ 2, direction });

                if (a.charAt(right) != b.charAt(left)) {
                    int reverseDirection = getReverse(direction);
                    executeQueue.add(new int[]{ 1, reverseDirection });
                }

                if (b.charAt(right) != c.charAt(left)) {
                    int reverseDirection = getReverse(direction);
                    executeQueue.add(new int[]{ 3, reverseDirection });

                    if (c.charAt(right) != d.charAt(left)) {
                        reverseDirection = getReverse(reverseDirection);
                        executeQueue.add(new int[]{ 4, reverseDirection });
                    }
                }
            }
            else if (clockNum == 3) {
                executeQueue.add(new int[]{ 3, direction });

                if (c.charAt(right) != d.charAt(left)) {
                    int reverseDirection = getReverse(direction);
                    executeQueue.add(new int[]{ 4, reverseDirection });
                }

                if (b.charAt(right) != c.charAt(left)) {
                    int reverseDirection = getReverse(direction);
                    executeQueue.add(new int[]{ 2, reverseDirection });

                    if (a.charAt(right) != b.charAt(left)) {
                        reverseDirection = getReverse(reverseDirection);
                        executeQueue.add(new int[]{ 1, reverseDirection });
                    }
                }
            }
            else {
                executeQueue.add(new int[]{ 4, direction });

                if (c.charAt(right) != d.charAt(left)) {
                    int reverseDirection = getReverse(direction);
                    executeQueue.add(new int[]{ 3, reverseDirection });

                    if (b.charAt(right) != c.charAt(left)) {
                        reverseDirection = getReverse(reverseDirection);
                        executeQueue.add(new int[]{ 2, reverseDirection });

                        if (a.charAt(right) != b.charAt(left)) {
                            reverseDirection = getReverse(reverseDirection);
                            executeQueue.add(new int[]{ 1, reverseDirection });
                        }
                    }
                }
            }

            while (!executeQueue.isEmpty()) {
                cur = executeQueue.poll();
                int num = cur[0];
                int dir = cur[1];

                if (dir == 1) {
                    if (num == 1) {
                        a = rightDirection(a);
                    } else if (num == 2) {
                        b = rightDirection(b);
                    } else if (num == 3) {
                        c = rightDirection(c);
                    } else {
                        d = rightDirection(d);
                    }
                } else {
                    if (num == 1) {
                        a = leftDirection(a);
                    } else if (num == 2) {
                        b = leftDirection(b);
                    } else if (num == 3) {
                        c = leftDirection(c);
                    } else {
                        d = leftDirection(d);
                    }
                }
            }
        }

        int answer = 0;

        if (a.charAt(0) == '1') {
            answer += 1;
        }

        if (b.charAt(0) == '1') {
            answer += 2;
        }

        if (c.charAt(0) == '1') {
            answer += 4;
        }

        if (d.charAt(0) == '1') {
            answer += 8;
        }

        bw.write(String.valueOf(answer));
    }

    static int getReverse(int direction) {
        if (direction == 1) {
            return -1;
        }

        return 1;
    }

    static String leftDirection(String s) {
        StringBuilder ret = new StringBuilder();

        for (int i = 1; i < s.length(); i++) {
            ret.append(s.charAt(i));
        }

        ret.append(s.charAt(0));

        return ret.toString();
    }

    static String rightDirection(String s) {
        StringBuilder ret = new StringBuilder();

        ret.append(s.charAt(s.length() - 1));

        for (int i = 0; i < s.length() - 1; i++) {
            ret.append(s.charAt(i));
        }

        return ret.toString();
    }
}
