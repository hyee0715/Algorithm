import java.util.ArrayList;
import java.util.List;

class StringIterator {
    List<Pair> list;

    public StringIterator(String compressedString) {
        list = new ArrayList<>();

        char c = 'a';
        StringBuilder num = new StringBuilder();
        for (int i = 0; i < compressedString.length(); i++) {
            if ((compressedString.charAt(i) >= 'a' && compressedString.charAt(i) <= 'z') || (compressedString.charAt(i) >= 'A' && compressedString.charAt(i) <= 'Z')) {
                if (num.length() != 0) {
                    list.add(new Pair(c, Integer.parseInt(num.toString())));
                }

                c = compressedString.charAt(i);
                num.setLength(0);

                continue;
            }

            num.append(compressedString.charAt(i));
        }

        if (num.length() != 0) {
            list.add(new Pair(c, Integer.parseInt(num.toString())));
        }
    }

    public char next() {
        if (list.isEmpty()) {
            return ' ';
        }

        char ret = list.get(0).getC();
        int num = list.get(0).getN() - 1;

        list.set(0, new Pair(ret, num));

        if (num <= 0) {
            list.remove(0);
        }

        return ret;
    }

    public boolean hasNext() {
        if (!list.isEmpty()) {
            return true;
        }

        return false;
    }
}

class Pair {
    char c;
    int n;

    Pair (char c, int n) {
        this.c = c;
        this.n = n;
    }

    char getC() {
        return c;
    }

    int getN() {
        return n;
    }
}

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */