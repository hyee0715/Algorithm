class TwoSum {
public:
	vector<int> v;

	TwoSum() {

	}

	void add(int number) {
		v.push_back(number);
	}

	bool find(int value) {
		sort(v.begin(), v.end());

		int left = 0, right = v.size() - 1;

		while (left < right) {
			long long sum = v[left] + v[right];

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
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */