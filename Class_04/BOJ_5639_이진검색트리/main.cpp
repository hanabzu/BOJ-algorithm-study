/* hanabzu */
/* BOJ_5639 이진 검색 트리 */

#include <iostream>

using namespace std;

class Node {
public:
	int value;
	Node* right = NULL;
	Node* left = NULL;

	Node(int value) {
		this->value = value;
	}
};

int N;
char p, l, r;
Node* root;

void make_tree(Node* root, int num);
void post_order(Node* root);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	cin >> num;
	root = new Node(num);

	while (cin >> num) {
		make_tree(root, num);
	}
	post_order(root);
}

void make_tree(Node* p, int num) {
	while (true) {
		if (num < p->value) {
			if (!p->left) {
				p->left = new Node(num);
				return;
			}
			p = p->left;
		}
		else {
			if (!p->right) {
				p->right = new Node(num);
				return;
			}
			p = p->right;
		}
	}

}

void post_order(Node* root) {
	if (root) {
		post_order(root->left);
		post_order(root->right);
		cout << root->value << '\n';
	}
}