#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<pair<int, int>> magic; //방향, 거리
unordered_map<int, int> explosion; //구슬 번호, 폭발 개수
int answer = 0;

int dx[] = {0, 1, 0, -1}; //서,남,동,북
int dy[] = {-1, 0, 1, 0,};

int convertDirection(int dir) {
	if (dir == 1) {
		return 3;
	}
	else if (dir == 2) {
		return 1;
	}
	else if (dir == 3) {
		return 0;
	}
	else {
		return 2;
	}
}

void input() {
	cin >> n >> m;

	board.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		int dir = convertDirection(a);

		magic.push_back({ dir, b });
	}
}

void settingBoard() {
	int x = ((n + 1) / 2) - 1;
	int y = ((n + 1) / 2) - 1;
	int dir = 0;

	int num = 1;
	int repeat = 1;
	bool flag = false;

	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < repeat; j++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				board[nx][ny] = num;
				num++;

				if (num == n * n) {
					flag = true;
					break;
				}

				x = nx;
				y = ny;

				if (j == repeat - 1) {
					dir++;

					if (dir == 4) {
						dir = 0;
					}
				}
			}

			if (i == 1) {
				repeat++;
			}

			if (flag) {
				break;
			}
		}

		if (flag) {
			break;
		}
	}
}

void blizzard(int direction, int distance) {
	int x = ((n + 1) / 2) - 1;
	int y = ((n + 1) / 2) - 1;

	for (int i = 0; i < distance; i++) {
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		board[nx][ny] = 0;

		x = nx;
		y = ny;
	}
}

vector<int> getVectorExceptZero() {
	vector<int> v;

	int x = ((n + 1) / 2) - 1;
	int y = ((n + 1) / 2) - 1;
	int dir = 0;

	int num = 1;
	int repeat = 1;
	bool flag = false;

	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < repeat; j++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (board[nx][ny] != 0) {
					v.push_back(board[nx][ny]);
				}

				num++;

				if (num == n * n) {
					flag = true;
					break;
				}

				x = nx;
				y = ny;

				if (j == repeat - 1) {
					dir++;

					if (dir == 4) {
						dir = 0;
					}
				}
			}

			if (i == 1) {
				repeat++;
			}

			if (flag) {
				break;
			}
		}

		if (flag) {
			break;
		}
	}

	return v;
}

void resettingBoard(vector<int>& nums) {
	board.clear();
	board.assign(n, vector<int>(n, 0));

	int x = ((n + 1) / 2) - 1;
	int y = ((n + 1) / 2) - 1;
	int dir = 0;

	int repeat = 1;
	bool flag = false;
	int idx = 0;

	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < repeat; j++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				board[nx][ny] = nums[idx];
				idx++;

				if (idx == nums.size()) {
					flag = true;
					break;
				}

				x = nx;
				y = ny;

				if (j == repeat - 1) {
					dir++;

					if (dir == 4) {
						dir = 0;
					}
				}
			}

			if (i == 1) {
				repeat++;
			}

			if (flag) {
				break;
			}
		}

		if (flag) {
			break;
		}
	}
}

vector<int> explode(vector<int>& marble) {
	vector<int> nums;
	vector<int> temp, v;

	for (int i = 0; i < marble.size(); i++) {
		nums.push_back(marble[i]);
	}

	while (1) {
		bool flag = false;

		for (int i = 0; i < nums.size(); i++) {
			if (temp.empty() || temp[temp.size() - 1] == nums[i]) {
				temp.push_back(nums[i]);
			}
			else if (temp[temp.size() - 1] != nums[i]) {
				if (temp.size() >= 4) {
					flag = true;

					int num = temp[0];
					int cnt = temp.size();

					explosion[num] += cnt;

					temp.clear();
				}
				else {
					for (int j = 0; j < temp.size(); j++) {
						v.push_back(temp[j]);
					}
					temp.clear();
				}

				i--;
				
			}
		}

		if (!temp.empty() && temp.size() >= 4) {
			flag = true;

			int num = temp[0];
			int cnt = temp.size();

			explosion[num] += cnt;

			temp.clear();
		}
		else if (!temp.empty() && temp.size() < 4) {
			for (int j = 0; j < temp.size(); j++) {
				v.push_back(temp[j]);
			}
			temp.clear();
		}

		nums.clear();

		for (int i = 0; i < v.size(); i++) {
			nums.push_back(v[i]);
		}

		v.clear();
			
		if (!flag) {
			break;
		}
	}

	return nums;
}

vector<int> convert(vector<int>& nums) {
	vector<int> ret;
	
	int left = 0;
	int right = 0;

	while (right < nums.size()) {
		right++;

		if (right == nums.size()) {
			int num = nums[left];
			int cnt = right - left;

			ret.push_back(cnt);
			ret.push_back(num);

			break;
		}

		if (nums[left] != nums[right]) {
			int num = nums[left];
			int cnt = right - left;
			
			ret.push_back(cnt);
			ret.push_back(num);

			left = right;
		}
	}

	return ret;
}

vector<int> cutVector(vector<int>& nums) {
	vector<int> ret;

	for (int i = 0; i < (n * n) - 1; i++) {
		ret.push_back(nums[i]);
	}

	return ret;
}

bool validateZeroMarble() {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 1 || board[i][j] == 2 || board[i][j] == 3)
			return true;
		}
	}

	return false;
}

void solution() {
	if (!validateZeroMarble()) {
		cout << 0;
		return;
	}
	
	for (int magicCount = 0; magicCount < m; magicCount++) {
		//마법 시전
		blizzard(magic[magicCount].first, magic[magicCount].second);

		//빈자리 메우기
		vector<int> nums = getVectorExceptZero();
		resettingBoard(nums);

		//구슬 폭발시키기
		nums = getVectorExceptZero();
		nums = explode(nums);

		if (nums.empty()) {
			break;
		}

		resettingBoard(nums);

		//구슬 변화시키기
		nums = getVectorExceptZero();
		nums = convert(nums);

		if (nums.size() > (n * n) - 1) {
			nums = cutVector(nums);
		}

		resettingBoard(nums);
	}

	for (pair<int, int> m : explosion) {
		answer += m.first * m.second;
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();
	
	return 0;
}