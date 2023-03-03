class MinStack {
public:
	stack<int> stk;
	map<int, int> mp;

	MinStack() {

	}

	void push(int val) {
		stk.push(val);
		mp[val]++;
	}

	void pop() {
		int n = stk.top();
		stk.pop();
		mp[n]--;
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		int n;
		for (pair<int, int> m : mp) {
			if (m.second > 0) {
				n = m.first;
				break;
			}
		}

		return n;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */