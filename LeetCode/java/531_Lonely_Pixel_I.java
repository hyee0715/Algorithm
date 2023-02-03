import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int findLonelyPixel(char[][] picture) {
        Map<Integer, Integer> rowMap = new HashMap<>();
        Map<Integer, Integer> colMap = new HashMap<>();
        List<Pair> bLocation = new ArrayList<>();
        int answer = 0;

        for (int i = 0; i < picture.length; i++) {
            for (int j = 0; j < picture[i].length; j++) {
                if (picture[i][j] == 'B') {
                    rowMap.put(i, rowMap.getOrDefault(i, 0) + 1);
                    colMap.put(j, colMap.getOrDefault(j, 0) + 1);

                    Pair p = new Pair(i, j);
                    bLocation.add(p);
                }
            }
        }

        for (int i = 0; i < bLocation.size(); i++) {
            if (rowMap.get(bLocation.get(i).getRow()) <= 1 && colMap.get(bLocation.get(i).getCol()) <= 1) {
                answer++;
            }
        }

        return answer;
    }
}

class Pair {
    int row;
    int col;

    Pair(int row, int col) {
        this.row = row;
        this.col = col;
    }

    int getRow() {
        return row;
    }

    int getCol() {
        return col;
    }
}