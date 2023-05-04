import java.io.*;

public class Main {
    static String s;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        s = br.readLine();
    }

    private static boolean checkJava(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
                return true;
            }
        }

        return false;
    }

    private static boolean checkCpp(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '_') {
                return true;
            }
        }

        return false;
    }

    private static boolean errorCheck(String s) {
        boolean isJava = checkJava(s);
        boolean isCpp = checkCpp(s);

        if (isJava && isCpp) {
            return false;
        }

        if ((s.charAt(0) == '_') || (s.charAt(0) >= 'A' && s.charAt(0) <= 'Z')) {
            return false;
        }

        if (s.charAt(s.length() - 1) == '_') {
            return false;
        }

        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1) && s.charAt(i) == '_') {
                return false;
            }
        }

        return true;
    }

    private static String makeCpp(String s) {
        StringBuilder ret = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
                ret.append("_");
                ret.append(Character.toLowerCase(s.charAt(i)));
            } else {
                ret.append(s.charAt(i));
            }
        }

        return ret.toString();
    }

    private static String makeJava(String s) {
        StringBuilder ret = new StringBuilder();

        boolean up = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '_') {
                up = true;
            } else {
                if (up) {
                    ret.append(Character.toUpperCase(s.charAt(i)));
                    up = false;
                } else {
                    ret.append(s.charAt(i));
                }
            }
        }

        return ret.toString();
    }

    private static void solution() throws IOException {
        if (!errorCheck(s)) {
            bw.write("Error!");
            return;
        }

        if (checkJava(s)) {
            bw.write(makeCpp(s));
            return;
        }

        bw.write(makeJava(s));
    }
}