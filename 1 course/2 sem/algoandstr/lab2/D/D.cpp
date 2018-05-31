#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CTree{
	private:
		struct node{
			node() = delete;
			bool zero;
			int count, value, priority;
			node *right_child, *left_child;
			explicit node(int val){
				count = 1;
				value = val;
				left_child = 	nullptr;
				right_child = nullptr;
				zero = value == 0;
				priority = rand() << 15 + rand();
			}
		};
	node *root;
	public:
		CTree(int n) : root(nullptr){
			for (int i = 0; i < n; i++){
				insert(new node(0), i);
			}
		}
		vector<int> toArray() {
			vector<int> result;
			toArray(root, result);
			return result;
		}
		void insert(int index, int value){
			node *left_node, *right_node, *mid_node = nullptr, *zero_node = nullptr;
			split(root, left_node, right_node, index);
			splitZero(right_node, mid_node, right_node, right_node);
			split(right_node, zero_node, right_node, 1);
			merge(root, left_node, new node(value));
			merge(root, root, mid_node);
			merge(root, root, right_node);
		}
	private:
		int getCount(node *root){
			if (root != nullptr){
				return root->count;
			}
			return 0;
		}
	bool getZero(node *root){
		if (root != nullptr){
			return root->zero;
		}
		return false;
	}
	
	void update(node *root){
		if (root != nullptr){
			root->count = 1 + getCount(root->left_child) + getCount(root->right_child);
			root->zero = (root->value == 0) || getZero(root->left_child) ||getZero(root->right_child);
		}
	}
	
	void insert(node *vertex, int key) {
		node *left_node, *right_node;
		split(root, left_node, right_node, key);
		merge(left_node, left_node, vertex);
		merge(root, left_node, right_node);
	}
	
	void split(node *root, node *&left_node, node *&right_node, int key, int add = 0) {
		if (root == nullptr) {
			left_node = right_node = nullptr;
			return;
		}
		int cur_key = add + getCount(root->left_child);
		if (key <= cur_key) {
			split(root->left_child, left_node, root->left_child, key, add);
			right_node = root;
		} else {
			split(root->right_child, root->right_child, right_node, key, 1 + cur_key);
			left_node = root;
		}
		update(root);
	}
	void splitZero(node *root, node *&left_node, node *&right_node, node *root_node, int key = 0) {
		if (getZero(root) == false) {
			split(root_node, left_node, right_node, getCount(root) + key);
			return;
		} else if (getZero(root->left_child) || root->value == 0) {
			splitZero(root->left_child, left_node, right_node, root_node, key);
		} else {
			splitZero(root->right_child, left_node, right_node,	root_node, key + getCount(root->left_child) + 1);
		}
	}
	
	void merge(node *&root, node *left_node, node *right_node) {
		if (left_node == nullptr) {
			root = right_node;
		}
		else if (right_node == nullptr) {
			root = left_node;
		} else 
			if (left_node->priority > right_node->priority) {
				merge(left_node->right_child, left_node->right_child, right_node);
				root = left_node;
			} else {
				merge(right_node->left_child, left_node, right_node->left_child);
				root = right_node;
			}
		update(root);
	}
	
	void toArray(node *root, vector<int> &result) {
		if (root->left_child != nullptr) {
			toArray(root->left_child, result);		
		}
		result.push_back(root->value);
		if (root->right_child != nullptr) {
			toArray(root->right_child, result);	
		}
	}
};

int main(){
	int n, m;
	cin >> n >> m;
	CTree cartesian_tree(m);
	for (int i = 0; i < n; i++) {
		int index;
		cin >> index;
		cartesian_tree.insert(index - 1, i + 1);
	}
	vector<int> resultArray = cartesian_tree.toArray();
	while (resultArray.empty() == false && resultArray.back() == 0) {
		resultArray.pop_back();
	}
	cout << resultArray.size() << endl;
	for (int i = 0; i < resultArray.size(); i++) {
		cout << resultArray[i] << ' ';
	}
	return 0;
}
