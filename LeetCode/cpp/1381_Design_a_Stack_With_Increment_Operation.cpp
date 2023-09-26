class CustomStack {
public:
	stack<int> st;
	int maxNum = 0;

	CustomStack(int maxSize) {
		maxNum = maxSize;
	}

	void push(int x) {
		if (st.size() < maxNum) {
			st.push(x);
		}
	}

	int pop() {
		if (!st.empty()) {
			int n = st.top();
			st.pop();
			return n;
		}
		else {
			return -1;
		}
	}

	void increment(int k, int val) {
		vector<int> arr(st.size(), 0);
		int idx = st.size() - 1;

		while (!st.empty()) {
			arr[idx--] = st.top();
			st.pop();
		}

		for (int i = 0; i < k; i++) {
			if (i == arr.size()) {
				break;
			}

			arr[i] = arr[i] + val;
		}

		for (int i = 0; i < arr.size(); i++) {
			st.push(arr[i]);
		}
	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */