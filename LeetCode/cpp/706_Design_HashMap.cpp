class MyHashMap {
public:
	unordered_map<int, int> um;

	MyHashMap() {

	}

	void put(int key, int value) {
		um[key] = value;
	}

	int get(int key) {
		if (um.count(key)) {
			return um[key];
		}

		return -1;
	}

	void remove(int key) {
		if (um.count(key)) {
			um.erase(key);
		}
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */