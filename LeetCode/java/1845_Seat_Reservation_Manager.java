import java.util.Map;
import java.util.TreeMap;

class SeatManager {
    Map<Integer, Integer> map = new TreeMap<>();

    public SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            map.put(i, 1);
        }
    }

    public int reserve() {
        int ret = 0;

        if (!map.isEmpty()) {
            for (int key : map.keySet()) {
                ret = key;
                break;
            }

            map.remove(ret);
        }

        return ret;
    }

    public void unreserve(int seatNumber) {
        map.put(seatNumber, 1);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.reserve();
 * obj.unreserve(seatNumber);
 */