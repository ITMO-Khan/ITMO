#include <limits>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

template<typename T, size_t NewBase = numeric_limits<T>::max()>
class BigInteger {
public:
    explicit BigInteger<T, NewBase>(long long value = 0);

    explicit operator BigInteger<T, NewBase>();

    BigInteger<T, NewBase>(const BigInteger<T, NewBase> &);

    BigInteger<T, NewBase>(BigInteger<T, NewBase> &&);

    BigInteger<T, NewBase> &operator+=(const BigInteger<T, NewBase> &);

    BigInteger<T, NewBase> operator+(const BigInteger<T, NewBase> &) const;

    BigInteger<T, NewBase> &operator-=(const BigInteger<T, NewBase> &);

    BigInteger<T, NewBase> operator-(const BigInteger<T, NewBase> &) const;

    BigInteger<T, NewBase> &operator*=(const BigInteger<T, NewBase> &);

    BigInteger<T, NewBase> operator*(const BigInteger<T, NewBase> &) const;

    BigInteger<T, NewBase> &operator/=(const size_t &);

    void transfer();

    bool isLess(const BigInteger<T, NewBase> &);

    size_t Size();

    bool check();

    T operator[](size_t id);

    string toString();
private:
    vector<int> intNumber;
    vector<T> number;

    bool isPos = true;

    int tmpCarry;
    int amountOfDigits;
    int bitsForBase;
    int tSize;

    const int POWER = numeric_limits<int>::digits10;
    const int BASE = (int) pow(10, numeric_limits<int>::digits10);

    template<typename U, size_t Base>
    friend istream &operator>>(istream &, BigInteger<U, Base> &);

    template<typename U, size_t Base>
    friend ostream &operator<<(ostream &, const BigInteger<U, Base> &);
};

template<typename T, size_t NewBase>
BigInteger<T, NewBase>::operator BigInteger<T, NewBase>() {

//????? ??? ?????, ?????????? ????? ?????-??, ???????? ?? ??, ??? ??? ???????? ???? ???? ?? ???????
    bitsForBase = 1;
    while ((1 << bitsForBase) < NewBase) {
        ++bitsForBase;
    }

    amountOfDigits = numeric_limits<T>::digits / bitsForBase;
    //  bigInt.number.assign(ceil(remainders.size() / (double) amountOfDigits), 0);


};

template<typename T, size_t NewBase>
BigInteger<T, NewBase>::BigInteger(long long value) {
    isPos = (value >= 0);

    value = llabs(value);

    while (value > 0) {
        intNumber.push_back(value % BASE);
        value /= BASE;
    }
    if (value != 0)
        this->transfer();
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase>::BigInteger(const BigInteger<T, NewBase> &other) {
    intNumber = other.intNumber;
    isPos = other.isPos;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase>::BigInteger(BigInteger<T, NewBase> &&other) {
    intNumber = other.intNumber;
    isPos = other.isPos;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> &BigInteger<T, NewBase>::operator+=(const BigInteger<T, NewBase> &other) {
    if (isPos == other.isPos) {
        int f = 0;
        for (int i = 0; f || i < max(intNumber.size(), other.intNumber.size()); ++i) {
            if (i == intNumber.size()) {
                intNumber.push_back(0);
            }

            if (i < other.intNumber.size()) {
                intNumber[i] += f + other.intNumber[i];
            }

            f = (intNumber[i] >= BASE);

            if (f)
                intNumber[i] -= BASE;
        }
    } else {
        isPos ^= true;
        *this -= other;
        isPos ^= true;
    }

    if (intNumber.back() == 0) {
        isPos = true;
    }
    this->transfer();
    return *this;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> BigInteger<T, NewBase>::operator+(const BigInteger<T, NewBase> &other) const {
    return BigInteger<T, NewBase>(*this) += other;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> &BigInteger<T, NewBase>::operator-=(const BigInteger<T, NewBase> &other) {

    if (isPos == other.isPos) {
        int f = 0;
        int ifLess = 1;

        if (isLess(other)) {
            isPos = !other.isPos;
            ifLess = -1;
            int diff = (int) other.intNumber.size() - (int) intNumber.size();
            for (int i = 0; i < diff; ++i) {
                intNumber.push_back(0);
            }
        }

        for (int i = 0; f || i < other.intNumber.size(); ++i) {
            intNumber[i] *= ifLess;
            intNumber[i] -= f;

            if (other.intNumber.size() > i)
                intNumber[i] -= (other.intNumber[i] * ifLess);

            f = (intNumber[i] < 0);

            if (f)
                intNumber[i] += BASE;
        }

        while (intNumber.size() > 1 && intNumber.back() == 0) {
            intNumber.pop_back();
        }
    } else {
        isPos ^= true;
        *this += other;
        isPos ^= true;
    }

    if (intNumber.back() == 0) {
        isPos = true;
    }

    this->transfer();
    return *this;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> BigInteger<T, NewBase>::operator-(const BigInteger<T, NewBase> &other) const {
    return BigInteger<T, NewBase>(*this) -= other;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> &BigInteger<T, NewBase>::operator*=(const BigInteger<T, NewBase> &other) {
    vector<int> product(intNumber.size() + other.intNumber.size());

    for (int i = 0; i < intNumber.size(); ++i) {
        int carry = 0;
        for (int j = 0; j < other.intNumber.size() || carry; ++j) {
            long long cur =
                    product[i + j] +
                    (long long) intNumber[i] * (long long) (j < other.intNumber.size() ? other.intNumber[j] : 0) +
                    carry;
            product[i + j] = cur % BASE;
            carry = int(cur / BASE);
        }
    }

//???? ??? ? ????? ?????? ????????
    while (product.size() > 1 && !product.back())
        product.pop_back();

    intNumber = product;
    isPos = (isPos == other.isPos);
    this->transfer();
    return *this;
}

template<typename T, size_t NewBase>
BigInteger<T, NewBase> BigInteger<T, NewBase>::operator*(const BigInteger<T, NewBase> &other) const {
    return BigInteger<T, NewBase>(*this) *= other;
}

template<typename T, size_t NewBase>
bool BigInteger<T, NewBase>::isLess(const BigInteger<T, NewBase> &other) {
    if (intNumber.size() == other.intNumber.size()) {
        for (int i = 0; i < intNumber.size(); ++i) {
            if (other.intNumber[i] > intNumber[i]) {
                return true;
            }
        }
    } else return other.intNumber.size() > intNumber.size();
}

template<typename T, size_t NewBase>
istream &operator>>(istream &in, BigInteger<T, NewBase> &bigInt) {
    string bigNumber;
    in >> bigNumber;

    int until = 0;
    if (bigNumber[0] == '-') {
        bigInt.isPos = false;
        until = 1;
    }

    for (int i = (int) bigNumber.length() - 1; i >= until;) {
        int p = 0;
        bigInt.intNumber.push_back(0);
        while (p < bigInt.POWER && i >= until) {
            int k = bigNumber[i] - '0';
            bigInt.intNumber.back() += k * pow(10, p++);
            --i;
        }
    }

    bigInt.transfer();
}

template<typename T, size_t NewBase>
void BigInteger<T, NewBase>::transfer() {
    vector<int> tmpIntNum = intNumber;
    vector<int> remainders;

    while (intNumber.back() != 0) {
        *this /= NewBase;
        remainders.push_back(tmpCarry);
    }
    tSize = int(remainders.size());

    bitsForBase = 1;
    while ((1 << bitsForBase) < NewBase) {
        ++bitsForBase;
    }

    amountOfDigits = numeric_limits<T>::digits / bitsForBase;
    number.assign(ceil(remainders.size() / (double) amountOfDigits), 0);

    int j = 0;
    for (int i = (int) remainders.size() - 1; i >= 0;) {
        int bitsCnt = 0;
        while (bitsCnt < amountOfDigits) {
            int tmp = (remainders[i] << (amountOfDigits - 1 - bitsCnt) * bitsForBase);
            number[j] |= tmp;
            ++bitsCnt;
            --i;
        }
        ++j;
    }

    intNumber = tmpIntNum;
};

template<typename T, size_t NewBase>
BigInteger<T, NewBase> &BigInteger<T, NewBase>::operator/=(const size_t &a) {
    tmpCarry = 0;

    for (auto i = (int) (intNumber.size() - 1); i >= 0; --i) {
        long long cur = (long long) tmpCarry * (long long) BASE;
        cur += intNumber[i];
        intNumber[i] = int(cur / a);
        tmpCarry = int(cur % a);
    }

    while (intNumber.size() > 1 && intNumber.back() == 0) {
        intNumber.pop_back();
    }

    return *this;
};

template<typename T, size_t NewBase>
ostream &operator<<(ostream &out, const BigInteger<T, NewBase> &other) {
    if (!other.isPos) {
        out << '-';
    }

    out << other.intNumber.back();
    if (other.intNumber.back() != 0) {
        for (int i = (int) other.intNumber.size() - 2; i >= 0; --i) {
            long long b = other.BASE;
            long long tmp = other.intNumber[i];
            while (b > 1) {
                b /= 10;
                out << tmp / b;
                tmp %= b;
            }
        }
    }
    return out;
}

template<typename T, size_t NewBase>
T BigInteger<T, NewBase>::operator[](size_t id) {
    T tmp = number[ceil(id / (double) amountOfDigits)];
    return number[ceil(id / (double) amountOfDigits)];
}

template<typename T, size_t NewBase>
size_t BigInteger<T, NewBase>::Size() {
    return tSize;
}

template<typename T, size_t NewBase>
bool BigInteger<T, NewBase>::check() {
    //????????? ????? ????? ???? ??? ?????? ????_????
    long long q = 0;
    for (int i = intNumber.size() - 1; i >= 0; --i) {
        q += intNumber[i] * pow(BASE, i);
    }
    string intInNormBase = to_string(q);
    transfer();
    string intIntTBase = "";

    long long d = 0;
    int gen = (1 << sizeof(T) * 8) - 1;
    for (int i = 0, p = tSize - 1; i < number.size(); ++i) {
        for (int k = 1, h = amountOfDigits - 1; p >= 0, k <= amountOfDigits; ++k, --h) {
            int lSh = sizeof(T) * 8 - amountOfDigits * bitsForBase + (k - 1) * bitsForBase;
            int rSh = (amountOfDigits - k) * bitsForBase + lSh;
            int e = (number[i] << lSh)& gen;
            int f = ( e >> rSh) ;

            d += pow(NewBase, p) * f;
            --p;
        }
    }
    intIntTBase += to_string(d);


return intInNormBase == intIntTBase;
};

template <typename T, size_t NewBase>
string BigInteger<T, NewBase>::toString() {
    long long q = 0;
    for (int i = intNumber.size() - 1; i >= 0; --i) {
        long long h = intNumber[i] * pow(BASE, i);
        q += h;
    }
    return to_string(q);
};
