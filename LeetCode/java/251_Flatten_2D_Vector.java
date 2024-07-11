import java.util.ArrayList;
import java.util.List;

class Vector2D {
    List<Integer> list;
    int idx = 0;
    int maxSize = 0;

    public Vector2D(int[][] vec) {
        list = new ArrayList<>();
        idx = 0;
        maxSize = 0;

        for (int i = 0; i < vec.length; i++) {
            for (int j = 0; j < vec[i].length; j++) {
                list.add(vec[i][j]);
                maxSize++;
            }
        }
    }

    public int next() {
        return list.get(idx++);
    }

    public boolean hasNext() {
        if (idx < maxSize) {
            return true;
        }

        return false;
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D obj = new Vector2D(vec);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */