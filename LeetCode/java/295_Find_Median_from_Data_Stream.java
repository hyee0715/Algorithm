import java.util.Collections;
import java.util.PriorityQueue;

class MedianFinder {
    PriorityQueue<Double> hi = new PriorityQueue<>(Collections.reverseOrder());
    PriorityQueue<Double> lo = new PriorityQueue<>();

    public MedianFinder() {

    }

    public void addNum(int num) {
        hi.add((double)num);
        lo.add(hi.poll());

        while (hi.size() < lo.size()) {
            hi.add(lo.poll());
        }
    }

    public double findMedian() {
        int sum = 0;

        if (lo.size() == hi.size()) {
            sum += lo.peek();
            sum += hi.peek();

            return (double)sum / 2;
        }

        return hi.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */