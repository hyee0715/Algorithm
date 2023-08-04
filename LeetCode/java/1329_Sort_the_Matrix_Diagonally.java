import java.util.*;

class Solution {
    public int[][] diagonalSort(int[][] mat) {
        Map<Pair, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                Pair pair;
                if (i <= j) {
                    pair = new Pair(i - i, j - i);
                } else {
                    pair = new Pair(i - j, j - j);
                }

                if (!map.containsKey(pair)) {
                    map.put(pair, new ArrayList<>());
                }

                map.get(pair).add(mat[i][j]);
            }
        }

        for (Pair key : map.keySet()) {
            List<Integer> list = map.get(key);

            Collections.sort(list);

            int x = key.getX();
            int y = key.getY();

            for (int i = 0; i < list.size(); i++) {
                mat[x][y] = list.get(i);

                x++;
                y++;
            }
        }

        return mat;
    }
}

class Pair {
    int x;
    int y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair pair = (Pair) o;
        return x == pair.x &&
                y == pair.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}