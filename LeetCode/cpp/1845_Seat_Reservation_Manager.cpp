class SeatManager {
public:
	map<int, int> mp; //idx, 상태 (사실상 빈 좌석만 맵에 들어감)

	SeatManager(int n) {
		for (int i = 1; i <= n; i++) {
			mp[i] = 1;
		}
	}

	int reserve() {
		int ret = 0;

		if (!mp.empty()) {
			for (auto m : mp) {
				ret = m.first;
				break;
			}

			mp.erase(ret);
		}

		return ret;
	}

	void unreserve(int seatNumber) {
		mp[seatNumber] = 1;
	}
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */