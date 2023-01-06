class MedianFinder {
public:
	priority_queue<double> hi;
	priority_queue<double, vector<double>, greater<>> lo;

	MedianFinder() {

	}

	void addNum(int num) {
		hi.push(num);
		lo.push(hi.top());
		hi.pop();

		while (hi.size() < lo.size()) {
			hi.push(lo.top());
			lo.pop();
		}
	}

	double findMedian() {
		int sum = 0;

		if (lo.size() == hi.size()) {
			sum += lo.top();
			sum += hi.top();

			return (double)sum / 2;
		}

		return hi.top();
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */