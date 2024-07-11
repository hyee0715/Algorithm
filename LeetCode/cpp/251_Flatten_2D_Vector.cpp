class Vector2D {
public:
	vector<int> v;
	int idx;
	int maxSize;

	Vector2D(vector<vector<int>>& vec) {
		idx = 0;
		maxSize = 0;

		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < vec[i].size(); j++) {
				v.push_back(vec[i][j]);
				maxSize++;
			}
		}
	}

	int next() {
		return v[idx++];
	}

	bool hasNext() {
		if (idx < maxSize) {
			return true;
		}

		return false;
	}
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */