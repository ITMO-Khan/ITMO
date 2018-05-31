#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("permutation.in");
ofstream fout("permutation.out");

template<typename T, typename S>
struct PermutationData {
    struct SumData {
        S *sum;
        explicit SumData(int n) {
            sum = new S[n];
            sum[0] = 1;
            for (int i = 1; i < n; ++i) {
                sum[i] = sum[i - 1] + i + 1;
            }
        }

        S get(int length) {
            return sum[length - 1];
        }
    };

    struct HashData {
        T *hash;

        explicit HashData(int n) {
            hash = new T[n];
            for (int i = 0; i < n; ++i) {
                hash[i] = generate(i + 1);
            }
        }

        T get(int i) {
            return hash[i - 1];
        }

        T generate(T value, T a = 113) {
            T res = 1;
            while (value) {
                if (value & 1) {
                    res *= a;
                }
                a *= a;
                value >>= 1;
            }
            return res;
        }
    };

    struct HashSumData {
        S *sum;

        explicit HashSumData(int n, HashData *hashes) {
            sum = new S[n];
            sum[0] = hashes->get(1);
            for (int i = 1; i < n; ++i) {
                sum[i] = sum[i - 1] + hashes->get(i + 1);
            }
        }

        S get(int length) {
            return sum[length - 1];
        }
    };

    SumData *sums;
    HashData *hashes;
    HashSumData *hashSums;

    explicit PermutationData(int n) {
        sums = new SumData(n);
        hashes = new HashData(n);
        hashSums = new HashSumData(n, hashes);
    }
};

PermutationData<unsigned int, unsigned long long> *permutationData;

template<typename S>
struct HashSumTree {
    struct Result {
        S sum, hashSum;

        Result() {
            sum = hashSum = 0;
        }

        explicit Result(int length) {
            sum = permutationData->sums->get(length);
            hashSum = permutationData->hashSums->get(length);
        }

        Result(S sum, S hashSum) : sum(sum), hashSum(hashSum) {}

        void initHash() {
            hashSum = permutationData->hashes->get(sum);
        }

        bool operator==(Result other) {
            return (sum == other.sum) && (hashSum == other.hashSum);
        }

        Result operator+(Result second) {
            return Result(sum + second.sum, hashSum + second.hashSum);
        }
    } neutral;

    int begin, end;
    HashSumTree *lChild, *rChild;
    Result data;

    HashSumTree(int begin, int end) : begin(begin), end(end), lChild(nullptr), rChild(nullptr) {
        if (size() > 1) {
            int mid = (begin + end) / 2;
            lChild = new HashSumTree(begin, mid);
            rChild = new HashSumTree(mid, end);
            data = lChild->data + rChild->data;
        } else {
            fin >> data.sum;
            data.initHash();
        }
    }

    void update(int &index, int &value) {
        if (lChild != nullptr) {
            (index < lChild->end ? lChild : rChild)->update(index, value);
            data = lChild->data + rChild->data;
        } else {
            data.sum = value;
            data.initHash();
        }
    }

    bool isPermutation(int begin, int end) {
        Result correct(end - begin);
        return calc(begin, end) == correct;
    }

    Result calc(int begin, int end) {
        if (begin >= end) {
            return neutral;
        } else if (begin == this->begin && end == this->end) {
            return data;
        } else {
            return lChild->calc(begin, min(end, lChild->end)) +
                   rChild->calc(max(begin, rChild->begin), end);
        }
    }

    int size() {
        return end - begin;
    }
};

int main() {
    int n, m;
    fin >> n;
    permutationData = new PermutationData<unsigned int, unsigned long long>(n);
    HashSumTree<unsigned long long> tree(0, n);
    fin >> m;
    for (int i = 0; i < m; ++i) {
        int t, x, y;
        fin >> t >> x >> y;
        --x;
        switch (t) {
            case 1:
                tree.update(x, y);
                break;
            case 2:{
                if (tree.isPermutation(x, y) == true){
					fout << "YES" << endl;
				} else
					fout << "NO" << endl;
                break;
            }
        }
    }
}
