import java.util.ArrayList;
import java.util.List;

class Solution {
    public void duplicateZeros(int[] arr) {
        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {
            if (list.size() == arr.length)
                break;

            if (arr[i] != 0) {
                list.add(arr[i]);
            } else {
                for (int j = 0; j < 2; j++) {
                    list.add(0);

                    if (list.size() == arr.length)
                        break;
                }
            }
        }

        for (int i = 0; i < list.size(); i++) {
            arr[i] = list.get(i);
        }
    }
}