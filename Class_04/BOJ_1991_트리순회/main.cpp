/* hanabzu* /
/* BOJ_1991 트리 순회 */

#include <iostream>

using namespace std;

class Node {
public:
	char alpha;
	Node* right = NULL;
	Node* left = NULL;

	Node(char alpha) {
		this->alpha = alpha;
	}
};

int N;
char p, l, r;
Node* nodes[26] = {};

void pre_order(Node* root);
void in_order(Node* root);
void post_order(Node* root);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 26; i++) {
		nodes[i] = new Node(i + 65);
	}
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p >> l >> r;
		p -= 65;
		if (l != '.') {
			l -= 65;
			nodes[p]->left = nodes[l];
		}
		else {
			nodes[p]->left = NULL;
		}
		if (r != '.') {
			r -= 65;
			nodes[p]->right = nodes[r];
		}
		else {
			nodes[p]->right = NULL;
		}
	}
	pre_order(nodes[0]);
	cout << '\n';
	in_order(nodes[0]);
	cout << '\n';
	post_order(nodes[0]);

	return 0;
}

void pre_order(Node* root) {
	if (root) {
		cout << root->alpha;
		pre_order(root->left);
		pre_order(root->right);
	}
}
void in_order(Node* root) {
	if (root) {
		in_order(root->left);
		cout << root->alpha;
		in_order(root->right);
	}
}
void post_order(Node* root) {
	if (root) {
		post_order(root->left);
		post_order(root->right);
		cout << root->alpha;
	}
}