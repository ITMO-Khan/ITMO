#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class BigInteger {
    static const int BASE = 1000000000;
    vector<int> number;
    bool sign;
public:
    BigInteger() {
    	this->sign = false;
	}
			
    BigInteger(string str) {
        if (str.length() == 0) {
                this->sign = false;
        }
        else {
                if (str[0] == '-') {
                        str = str.substr(1);
                        this->sign = true;
                }
                else {
                        this->sign = false;
                }

                for (long long i = str.length(); i > 0; i -= 9) {
                        if (i < 9)
                                this->number.push_back(atoi(str.substr(0, i).c_str()));
                        else
                                this->number.push_back(atoi(str.substr(i - 9, 9).c_str()));
                }

                while (this->number.size() > 1 && this->number.back() == 0) {
                this->number.pop_back();
        		}

        	if (this->number.size() == 1 && this->number[0] == 0) this->sign = false;
        }
	}
	
    BigInteger(long long value) {
        if (value < 0) { 
			this->sign = true; value = -value; 
		} else 
			this->sign = false;
        do {
                this->number.push_back(value % BASE);
                value /= BASE;
        } while (value != 0);
	}
	
    BigInteger(const BigInteger &arg)
	{
	    sign  = arg.sign;
	    number = arg.number;
	}

    friend ostream& operator <<(ostream& os, const BigInteger& bi) {

        if (bi.number.empty()) 
			os << 0;
        else {
                if (bi.sign) 
					os << '-';
                os << bi.number.back();
                char old_fill = os.fill('0');
                for (long long i = static_cast<long long>(bi.number.size()) - 2; i >= 0; --i) 
					os << setw(9) << bi.number[i];
                os.fill(old_fill);
        }

        return os;
	}
	
	friend istream& operator>>(istream& is, BigInteger& a)
	{
	    string s;
	    is >> s;
	    a = BigInteger(s);
	    return is;
	}
	
	friend bool operator ==(const BigInteger& left, const BigInteger& right) {
        if (left.sign != right.sign) 
			return false;
        if (left.number.empty()) {
                if (right.number.empty() || (right.number.size() == 1 && right.number[0] == 0)) 
					return true;
                else 
					return false;
        }

        if (right.number.empty()) {
                if (left.number.size() == 1 && left.number[0] == 0) 	
					return true;
                else 
					return false;
        }

        if (left.number.size() != right.number.size()) 
			return false;
        for (size_t i = 0; i < left.number.size(); ++i) 
			if (left.number[i] != right.number[i]) 
				return false;

        return true;
	}
	
    friend bool operator <(const BigInteger& left, const BigInteger& right) {
        if (left == right) 
			return false;
        if (left.sign) {
                if (right.sign) 
					return ((-right) < (-left));
                else 
					return true;
        } else 
			if (right.sign) 
				return false;
        else {
                if (left.number.size() != right.number.size()) {
                        return left.number.size() < right.number.size();
                } else {
                        for (long long i = left.number.size() - 1; i >= 0; --i) {
                                if (left.number[i] != right.number[i]) 
									return left.number[i] < right.number[i];
                        }

                        return false;
                }
        }
	}
	
    friend bool operator >(const BigInteger& left, const BigInteger& right) {
        return !(left < right) && !(left == right);
	}
	
    const BigInteger operator +() const {
        return BigInteger(*this);
	}
	
    const BigInteger operator -() const {
        BigInteger copy(*this);
        copy.sign = !copy.sign;
        return copy;
	}
	
    friend const BigInteger operator +(BigInteger left, const BigInteger& right) {
        if (left.sign) {
                if (right.sign) 
					return -(-left + -right);
                else 
					return right + left;
        }
        else 
			if (right.sign) 
				return left - (-right);
        int carry = 0;
        for (size_t i = 0; i < max(left.number.size(), right.number.size()) || carry != 0; ++i) {
                if (i == left.number.size()) 
					left.number.push_back(0);
                left.number[i] += carry + (i < right.number.size() ? right.number[i] : 0);
                carry = left.number[i] >= BASE;
                if (carry != 0) 
					left.number[i] -= BASE;
        }

        return left;
	}
	
    BigInteger& operator +=(const BigInteger& value) {
        return *this = (*this + value);
	}
	
    friend const BigInteger operator -(BigInteger left, const BigInteger& right) {
        if (right.sign) 
			return left + (-right);
        else 
			if (left.sign) 
				return -(-left + right);
        else 
			if (left < right) 
				return -(right - left);
        int carry = 0;
        for (size_t i = 0; i < right.number.size() || carry != 0; ++i) {
                left.number[i] -= carry + (i < right.number.size() ? right.number[i] : 0);
                carry = left.number[i] < 0;
                if (carry != 0) 
					left.number[i] += BASE;
        }

        while (left.number.size() > 1 && left.number.back() == 0) {
                left.number.pop_back();
        }

        if (left.number.size() == 1 && left.number[0] == 0) 
			left.sign = false;
        return left;
	}
	
    BigInteger& operator -=(const BigInteger& value) {
        return *this = (*this - value);
	}
};



int main() {
    BigInteger a, b;
    cin >> a >> b;
    cout << a + b << endl;
    cout << b + a << endl;
    cout << a - b << endl;
    cout << b - a << endl;
}
