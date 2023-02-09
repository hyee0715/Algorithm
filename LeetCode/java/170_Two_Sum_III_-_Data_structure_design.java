import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class TwoSum {
    List<Integer> list = new ArrayList<>();

    public TwoSum() {
    }

    public void add(int number) {
        list.add(number);
    }

    public boolean find(int value) {
        Collections.sort(list);

        int left = 0, right = list.size() - 1;

        while (left < right) {
            long sum = list.get(left) + list.get(right);

            if (sum == value) {
                return true;
            }

            if (sum < value) {
                left++;
                continue;
            }

            right--;
        }

        return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */