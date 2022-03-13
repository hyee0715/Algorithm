#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
using namespace std;

int n, m, answer, maxNum = 0;
vector<pair<int, pair<int, int> > > edges;
int parent[MAX];

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back(make_pair(c, make_pair(a, b)));
	}
}

int find_parent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find_parent(parent[x]);
}

bool same_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (x == y)
		return true;
	else
		return false;
}

void union_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

void solution() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < m; i++) {
		if (same_parent(edges[i].second.first, edges[i].second.second) == false) {
			union_parent(edges[i].second.first, edges[i].second.second);

			answer += edges[i].first;
			
			if (maxNum < edges[i].first) { 
				maxNum = edges[i].first;
			}
		}
	}

	cout << answer - maxNum << "\n"; // �� ���� ������ ������ �ϹǷ� ����� ���� �� ���� �� ���� �ϳ��� �����Ѵ�.
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}