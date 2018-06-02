#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
 
using namespace std;
int a[11111];
 
template <class T> struct seq {
    T val; 
    int size_, priority;
    seq<T> *l = 0, *r = 0, *p = 0;
    seq(T _v) : val(_v), size_(1) { 
        priority = rand(); 
    }
 
    static int size(seq<T> *c) { return c == 0 ? 0 : c->size_; }
    seq<T> *update() {
        size_ = 1;
        if (l != 0) {
            l->p = this;
            size_ += l->size_;
        }
        if (r != 0) {
            r->p = this;
            size_ += r->size_;
        }
        return this;
    }
    int index() {
        int ind = size(this->l);
        seq<T> *c = this;
        while (c->p != 0) {
            if (c->p->l != c) {
                ind += 1 + size(c->p->l);
            }
            c = c->p;
        }
        return ind;
    }
    seq<T> *root() {
        return this->p == 0 ? this : p->root(); 
    }
    seq<T> *min() {
        return this->l == 0 ? this : l->min(); 
    }
    seq<T> *max() {
        return this->r == 0 ? this : r->max(); 
    }
    seq<T> *next() { 
        return this->r == 0 ? this->p : this->r->min(); 
    }
    seq<T> *prev() { 
        return this->l == 0 ? this->p : this->l->max(); 
    }
};
 
template <class T> seq<T> *merge(seq<T> *A, seq<T> *B) {
    if (A == 0) {
        return B;
    }
    if (B == 0) {
        return A;
    }
    if (A->priority > B->priority) {
        A->r = merge(A->r, B);
        return A->update();
    } 
    B->l = merge(A, B->l);
    return B->update();
}
 
template <class T, typename... Seqs> seq<T> *merge(seq<T> *l, Seqs... seqs) {
    return merge(l, merge(seqs...));
}
 
template <class T> pair<seq<T> *, seq<T> *> split(seq<T> *A, int index) {
    if (A == 0) {
        return{ 0, 0 };
    }
    A->p = 0;
    if (index <= seq<T>::size(A->l)) {
        auto pr = split(A->l, index);
        A->l = pr.second;
        return{ pr.first, A->update() };
    }
    auto pr = split(A->r, index - (1 + seq<T>::size(A->l)));
    A->r = pr.first;
    return{ A->update(), pr.second };
}
 
template <class T> pair<seq<T> *, seq<T> *> split(seq<T> *A) {
    if (A == 0) {
        return{ 0, 0 };
    }
    seq<T> *B = A, *lr = A; 
    A = A->l;
    if (A == 0) {
        while (lr->p != 0 && lr->p->l == B) {
            lr = B = lr->p;
        }
        if (lr->p != 0) {
            lr = A = lr->p; 
            lr->r = B->p = 0;
        }
    } else {
        A->p = lr->l = 0;
    }
    while (lr->update()->p != 0) {
        if (lr->p->l == lr) {
            if (lr == A) {
                swap(A->p, B->p);
                B->p->l = B;
            }
            lr = B = B->p;
        } else {
            if (lr == B) {
                swap(A->p, B->p);
                A->p->r = A;
            }
            lr = A = A->p;
        }
    }
    return{ A, B };
}
 
struct EulerTourTree {
    struct edge { 
        int u, v; 
    };
    vector<seq<edge>> vertices;
    vector<unordered_map<int, seq<edge>>> edges;
    EulerTourTree(int n) {
        vertices.reserve(n); 
        edges.reserve(n);
        for (int i = 0; i < n; ++i) {
            add_vertex();
        }
    }
 
    int add_vertex() {
        int id = (int)vertices.size();
        vertices.push_back(edge{ id, id });
        edges.emplace_back();
        return id;
    }
 
    int root(int u) { 
        return vertices[u].root()->min()->val.u; 
    }
    bool connected(int u, int v) { 
        return vertices[u].root() == vertices[v].root(); 
    }
    int size(int u) { 
        return (vertices[u].root()->size_ + 2) / 3; 
    }
 
    void attach(int u, int v) {
        seq<edge> *i1, *i2;
        tie(i1, i2) = split(&vertices[v]); merge(i1, &(edges[v].emplace(u, seq<edge>{edge{ v, u }}).first)->second, vertices[u].root(), &(edges[u].emplace(v, seq<edge>{edge{ u, v }}).first)->second, i2);
    }
 
    void reroot(int u) {
        seq<edge> *i1, *i2;
        tie(i1, i2) = split(&vertices[u]);
        merge(i2, i1);
    }
 
    void link(int u, int v) { 
        reroot(u); attach(u, v); 
    }
 
    void cut(int u, int v) {
        auto uv = edges[u].find(v), vu = edges[v].find(u);
        if (uv->second.index() > vu->second.index()) {
            swap(u, v);
            swap(uv, vu);
        }
        seq<edge> *i1, *i2;
        tie(i1, i2) = split(&uv->second); 
        split(i2, 1);
        merge(i1, split(split(&vu->second).second, 1).second);
        edges[u].erase(uv); 
        edges[v].erase(vu);
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	for (int i = 0; i < 1111; i++){
		a[i] = i;
	}
    cin >> n >> m;
    EulerTourTree ett(n);
    string sBuf;
    while (m--) {
        int u, v;
        cin >> sBuf;
        switch (sBuf[0]) {
        case 's':
            int num;
            cin >> num;
            num--;
            cout << ett.size(num) << endl;
            break;
        case 'l':
            cin >> u >> v;
            u--; v--;
            ett.link(u, v);
            break;
        case 'c':
            cin >> u >> v;
            u--; v--;
            ett.cut(u, v);
            break;
        }
    }
    return 0;
}
