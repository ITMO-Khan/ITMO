#include <fstream>
#include <iostream>
#include <set>


using namespace std;

const int SET = 1000000000 + 1;
long long asd[11111111];
int n;

struct node {
    int max, sum, index, set;
    node * l, * r;

    node() {
        l = nullptr;
        r = nullptr;
        max = sum = index = 0;
        set = SET;
    }

    node(node * a, node * b) {
        l = a;
        r = b;
    }

    node(int ind) {
        l = r = nullptr;
        max = sum = 0;
        set = SET;
        index = ind;
    }

    ~node() {
        delete l;
        delete r;
    }

    void update_max_sum() {
        max = std::max(l->max, r->max + l->sum);
        sum = l->sum + r->sum;
    }
} tree_root;



void create_children(node * root, int l, int r) {
    if (root->l == nullptr) {
        root->l = new node((root->index << 1) + 1);
        root->r = new node((root->index << 1) + 2);
    }
    if (root->set == SET) return;
    root->sum = root->set * (r - l + 1);
    root->max = root->sum;
    if (l != r) {
        root->l->set = root->set;
        root->r->set = root->set;
    }
    root->set = SET;
}

void set_val(node * cur_node, int l, int r, int l_req, int r_req, int val) {
    create_children(cur_node, l, r);
    if (l_req > r || r_req < l) return;
    if (l_req <= l && r_req >= r) {
        cur_node->set = val;
        create_children(cur_node, l, r);
        return;
    }
    set_val(cur_node->l, l, l + (r - l) / 2, l_req, r_req, val);
    set_val(cur_node->r,  l + (r - l) / 2 + 1, r, l_req, r_req, val);
    cur_node->update_max_sum();
}

int get_ans(node * cur_node, int l, int r, int h) {
    create_children(cur_node, l, r);
    if (l == r) return l;
    create_children(cur_node->l, l, l + (r - l) / 2);
    if (cur_node->l->max > h) {
        return get_ans(cur_node->l, l, l + (r - l) / 2, h);
    } else {
        create_children(cur_node->r, l + (r - l) / 2 + 1, r);
        return get_ans(cur_node->r, l + (r - l) / 2 + 1, r, h - cur_node->l->sum);
    }
}

int main() {
    ios_base:: sync_with_stdio(false);
    cin >> n;
    char c;
	for (int i = 0; i < 1000; i++){
		asd[i] = i;
	}
    while (cin >> c) {
        switch (c) {
            case 'E':
                return 0;
            case 'I':
                int a, b, D;
                cin >> a >> b >> D;
                set_val(&tree_root, 0, n, a - 1, b - 1, D);
                break;
            case 'Q':
                int h;
                cin >> h;
                cout << get_ans(&tree_root, 0, n, h) << "\n";
                break;
        }
    }
}
