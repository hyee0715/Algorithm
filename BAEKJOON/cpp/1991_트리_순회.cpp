#include <iostream>
#include <vector>

#define MAX 26
using namespace std;

int n;
vector<char> tree[MAX];

void input() {
	cin >> n;
	char a, b, c;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;

		tree[a - 'A'].push_back(b);
		tree[a - 'A'].push_back(c);
	}
}

void preorder_traversal(int x) {
	x = x - 'A';

	if (tree[x][0] == '.' && tree[x][1] == '.') {
		cout << char('A' + x);
		return;
	}

	cout << char('A' + x);

	if (tree[x][0] != '.')
		preorder_traversal(tree[x][0]);

	if (tree[x][1] != '.')
		preorder_traversal(tree[x][1]);
}

void inorder_traversal(int x) {
	x = x - 'A';

	if (tree[x][0] == '.' && tree[x][1] == '.') {
		cout << char('A' + x);
		return;
	}

	if (tree[x][0] != '.')
		inorder_traversal(tree[x][0]);

	cout << char('A' + x);

	if (tree[x][1] != '.')
		inorder_traversal(tree[x][1]);
}

void postorder_traversal(int x) {
	x = x - 'A';

	if (tree[x][0] == '.' && tree[x][1] == '.') {
		cout << char('A' + x);
		return;
	}

	if (tree[x][0] != '.')
		postorder_traversal(tree[x][0]);

	if (tree[x][1] != '.')
		postorder_traversal(tree[x][1]);

	cout << char('A' + x);
}

void solution() {
	preorder_traversal('A');
	cout << "\n";

	inorder_traversal('A');
	cout << "\n";

	postorder_traversal('A');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}