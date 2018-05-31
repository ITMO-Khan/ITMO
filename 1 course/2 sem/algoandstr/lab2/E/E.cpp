#include <string>
#include <iostream>
#include <iomanip>
#include <climits>
#define ll long long
 
using namespace std;
  
struct node {
    ll key;
    ll sum;
    ll min, max;
    ll height;
    node * left;
    node * right;
 
    node(ll k) {
        key = k;
        min = k;
        max = k;
        sum = 0;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
 
    ~node() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
 
    ll get_height_left() {
        if (left == nullptr) {
            return 0;
        } else {
            return left->height;
        }
    }
 
    ll get_height_right() {
        if (right == nullptr) {
            return 0;
        } else {
            return right->height;
        }
    }
 
    ll get_balance() {
        return get_height_right() - get_height_left();
    }
 
    ll get_sum_left() {
        if (left) {
            return left->sum;
        }
        return 0;
    }
 
    ll get_sum_right() {
        if (right) {
            return right->sum;
        }
        return 0;
    }
 
    ll get_min_left() {
        if (left) {
            return left->min;
        }
        return LLONG_MAX;
    }
 
    ll get_min_right() {
        if (right) {
            return right->min;
        }
        return LLONG_MAX;
    }
 
    ll get_max_left() {
        if (left) {
            return left->max;
        }
        return LLONG_MIN;
    }
 
    ll get_max_right() {
        if (right) {
            return right->max;
        }
        return LLONG_MIN;
    }
 
    ll recalc_min_max() {
        this->min = std::min(std::min(get_min_left(), get_min_right()), key);
        this->max = std::max(std::max(get_max_left(), get_max_right()), key);
    }
 
    ll recalc_sum() {
        sum = get_sum_left() + get_sum_right();
        if (left) sum += left->key;
        if (right) sum += right->key;
    }
 
    void recalc() {
        height = 1 + std::max(this->get_height_left(), this->get_height_right());
    }
};
 
node * find(node * cur_node, int val) {
    if (cur_node == nullptr || cur_node->key == val) {
        return cur_node;
    }
 
    if (cur_node->key < val) {
        return find(cur_node->right, val);
    } else {
        return find(cur_node->left, val);
    }
}
 
bool exists(node * cur_node, ll val) {
    return find(cur_node, val) != nullptr;
}
 
node * right_rotate(node * cur_node) {
    node * left = cur_node->left;
 
    cur_node->left = left->right;
    left->right = cur_node;
 
    cur_node->recalc();
    cur_node->recalc_sum();
    cur_node->recalc_min_max();
 
    left->recalc();
    left->recalc_sum();
    left->recalc_min_max();
 
    return left;
}
 
node * left_rotate(node * cur_node) {
    node* right = cur_node->right;
 
    cur_node->right = right->left;
    right->left = cur_node;
 
    cur_node->recalc();
    cur_node->recalc_sum();
    cur_node->recalc_min_max();
 
    right->recalc();
    right->recalc_sum();
    right->recalc_min_max();
 
    return right;
}
 
node * rebalance(node * cur_node) {
    if (cur_node->get_balance() == 2) {
        if (cur_node->right->get_balance() < 0) {
            cur_node->right = right_rotate(cur_node->right);
        }
        return left_rotate(cur_node);
    }
    if (cur_node->get_balance() == -2) {
        if (cur_node->left->get_balance() > 0) {
            cur_node->left = left_rotate(cur_node->left);
        }
        return right_rotate(cur_node);
    }
    return cur_node;
}
 
node * insert(node * cur_node, ll new_key) {
    if (cur_node == nullptr) {
        return new node(new_key);
    }
 
    if (new_key < cur_node->key) {
        cur_node->left = insert(cur_node->left, new_key);
    } else {
        cur_node->right = insert(cur_node->right, new_key);
    }
    cur_node->recalc();
    cur_node->recalc_sum();
    cur_node->recalc_min_max();
 
    return rebalance(cur_node);
}
 
node * insert_node(node * cur_node, ll new_key) {
    if (exists(cur_node, new_key)) {
        return cur_node;
    }
    return insert(cur_node, new_key);
}
 
node * next_value(node * root, int val) {
    node * current = root;
    node * successor = nullptr;
 
    while (current != nullptr) {
        if (current->key > val) {
            successor = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return successor;
}
 
node * prev_value(node * root, int val) {
    node* current = root;
    node* successor = nullptr;
 
    while (current != nullptr) {
        if (current->key < val) {
            successor = current;
            current = current->right;
        }
        else {
            current = current->left;
        }
    }
    return successor;
}
 
node * find_min(node * cur_node) {
    if (cur_node->left == nullptr) {
        return cur_node;
    }
    return find_min(cur_node->left);
}
 
node * remove_min(node * cur_node) {
    if (cur_node->left == nullptr) {
        return cur_node->right;
    }
 
    cur_node->left = remove_min(cur_node->left);
    cur_node->recalc();
    cur_node->recalc_sum();
 
    return rebalance(cur_node);
}
 
node * delete_node(node * cur_node, ll val) {
    if (cur_node == nullptr) {
        return nullptr;
    }
 
    if (cur_node->key > val) {
        cur_node->left = delete_node(cur_node->left, val);
    } else if (cur_node->key < val) {
        cur_node->right = delete_node(cur_node->right, val);
    } else {
        node * left = cur_node->left;
        node * right = cur_node->right;
 
        if (right == nullptr) {
            return left;
        }
 
        node * min = find_min(right);
        min->right = remove_min(right);
        min->left = left;
 
        min->recalc();
        min->recalc_sum();
 
        return rebalance(min);
    }
    return rebalance(cur_node);
}
 
ll sum(node * cur_node, ll l, ll r) {
    if (cur_node == nullptr) {
        return 0;
    }
 
    if (cur_node->key > r) {
        return sum(cur_node->left, l, r);
    }
 
    if (cur_node->key < l) {
        return sum(cur_node->right, l, r);
    }
 
    if (cur_node->left == nullptr && cur_node->right == nullptr) {
        return cur_node->key;
    }
 
    if (cur_node->min >= l && cur_node->max <= r) {
        return cur_node->sum + cur_node->key;
    }
    return sum(cur_node->left, l, r) + sum(cur_node->right, l, r) + cur_node->key;
}
 
const ll TEN = 1000000000;
ll a[111111];
int main() {
	for (int i = 0; i < 111111; i++){
		a[i] = i;
	}
    node * root = nullptr;
    char prev = '+';
    ll res = 0;
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++){
        char c;
        cin >> c;
        if (c == '+') {
            ll x;
            cin >> x;
            if (prev == '?') {
                root = insert_node(root, (x + res) % TEN);
            } else {
                root = insert_node(root, x);
            }
        } else {
            ll l, r;
            cin >> l >> r;
            res = sum(root, l, r);
            cout << res << endl;
        }
        prev = c;
    }
    if (root) {
        delete root;
    }
}
