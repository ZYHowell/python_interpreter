#include <string>
#include <vector>
#include <iostream>

using namespace std;

class BigInt {
public:
	bool symbol; //标记数字的正负
	vector<int> num; //存储高精度整数

	BigInt(string sNum = "0") {
		*this = sNum;
	}

	BigInt(int iNum) {
		*this = iNum;
	}

	double to_double() const {
		double ret = 0;
		for (int i = num.size() - 1; i >= 0; --i){
			ret = ret * 10 + num[i];
		}
		return ret;
	}

	BigInt operator=(const int iNum) {
		num.erase(num.begin(), num.end());
		int tmp;
		if (iNum < 0) {
			symbol = true;
			tmp = -iNum;
		} else {
			symbol = false;
			tmp = iNum;
		}
//以倒序存储高精度整数
//将数字按位存数
		while (tmp >= 10) {
			num.push_back(tmp % 10);
			tmp /= 10;
		}
		if (tmp != 0) num.push_back(tmp);
		else if (num.empty()) num.push_back(0);
		return *this;
	}

//重载 = 运算符 使之支持用 = 直接用字符串进行赋值
	BigInt operator=(const string sNum) {
//清空原有数字
		num.erase(num.begin(), num.end());
//以倒序存储高精度整数
		for (string::size_type i(sNum.size() - 1); i > 0; --i) {
			num.push_back(sNum[i] - '0');
		}
//确定数字符号
		if (sNum[0] == '-') {
			symbol = true;
		} else {
			symbol = false;
			num.push_back(sNum[0] - '0');
		}
//清除前导零
		for (vector<int>::size_type i(num.size() - 1); num[i] == 0 && i > 0; --i) {
			num.pop_back();
		}
		return *this;
	}

//重载 = 运算符 使之支持用 = 直接高精度整数进行赋值
	BigInt operator=(const BigInt bInt) {
//清空原有数字
		num.erase(num.begin(), num.end());
//以倒序存储高精度整数
		for (vector<int>::size_type i(0); i < bInt.num.size(); ++i) {
			num.push_back(bInt.num[i]);
		}
//符号转存
		symbol = bInt.symbol;
		return *this;
	}

//重载 + 运算符 使之支持用 + 进行高精度整数的加法运算
	BigInt operator+(const BigInt bInt) const {
		BigInt rslt;
//同号相加
		if (bInt.symbol == (*this).symbol) {
			if (bInt.symbol) rslt.symbol = true; //同负
		} else if ((*this).symbol) //左负 右正
		{
			rslt = bInt - (-*this);
			rslt.symbol = true;
			return rslt;
		} else if (bInt.symbol) //左正 右负
		{
			rslt = *this - (-bInt);
			return rslt;
		}
//获取相加的两个数字的长度
		vector<int>::size_type lenA(num.size()), lenB(bInt.num.size()), lng;
		lng = (lenA > lenB ? lenA : lenB); //记录长度较长的
//逐位相加
		for (vector<int>::size_type i(0); i < lng; ++i) {
			int tmp(rslt.num[rslt.num.size() - 1]); //获取当前位原有的数字
//相加
			if (i < lenA) tmp += num[i];
			if (i < lenB) tmp += bInt.num[i];
			rslt.num[rslt.num.size() - 1] = tmp % 10; //存入
			rslt.num.push_back(tmp / 10); //进位
		}
		if (rslt.num[lng] == 0) rslt.num.pop_back(); //末位为0则弹出
		return rslt;
	}

//重载 - 运算符 使之支持用 - 进行高精度整数的加法运算
	BigInt operator-(BigInt bInt) const {
		BigInt rslt, myInt(*this), tmp;
//获取相加的两个数字的长度
		vector<int>::size_type lenA(num.size()), lenB(bInt.num.size()), lng, shrt, len;
		shrt = (lenA > lenB ? lenB : lenA); //记录长度较短的
		lng = (lenA > lenB ? lenA : lenB); //记录长度较长的
//同号相减
		if (bInt.symbol == myInt.symbol) {
			if (!bInt.symbol) //同正
			{
				if (myInt < bInt) {
					tmp = myInt;
					myInt = bInt;
					bInt = tmp; //交换
					rslt.symbol = true;
				}
			} else //同负
			{
				if (myInt > bInt) {
					tmp = myInt;
					myInt = bInt;
					bInt = tmp; //交换
					rslt.symbol = false;
				} else{
                    rslt.symbol = true;
				}
				myInt = -myInt;
				bInt = -bInt; //变正
				
			}
		} else if (myInt.symbol) return -(-myInt + bInt); //左负 右正
		else if (bInt.symbol) return myInt + (-bInt); //左正 右负
//逐位相减
		for (vector<int>::size_type i(0); i < lng; ++i) {
			if (i < shrt) {
//相减
				if (myInt.num[i] < bInt.num[i]) {
//借位
					myInt.num[i + 1] -= 1;
					rslt.num[i] = myInt.num[i] + 10 - bInt.num[i]; //减
				} else rslt.num[i] = myInt.num[i] - bInt.num[i]; //减
			} else rslt.num[i] = myInt.num[i];
			rslt.num.push_back(0);
		}
//消去前导0
		len = rslt.num.size();
		while (len--) {
			if (rslt.num[len] == 0) rslt.num.pop_back();
			else break;
		}
		if (rslt.num.empty()) rslt.num.push_back(0); //确保有零存在
		return rslt;
	}

//重载 - 运算符 使之支持用 - 进行高精度整数的加法运算 单目运算
	BigInt operator-() const {
		BigInt rslt(*this);
		rslt.symbol = !rslt.symbol;
		return rslt;
	}

//重载 * 运算符 使之支持用 * 进行高精度整数的乘法运算
	BigInt operator*(const BigInt bInt) const {
		BigInt rslt;
//获取相乘的两个数字的长度
		vector<int>::size_type lenA(num.size()), lenB(bInt.num.size()), len(0);
//逐位相乘
		for (vector<int>::size_type i(0); i < lenA; ++i)
			for (vector<int>::size_type j(0); j < lenB; ++j)
				if (rslt.num.size() - 1 < i + j) {
					++len;
					rslt.num.push_back(num[i] * bInt.num[j]); //增加一位
				} else rslt.num[i + j] += num[i] * bInt.num[j];
//进位
		for (vector<int>::size_type i(0); i < len; ++i) {
			if (i + 1 < rslt.num.size()) {
				rslt.num[i + 1] += rslt.num[i] / 10;
			} else if (rslt.num[i] >= 10) {
				rslt.num.push_back(rslt.num[i] / 10);
				++len;
			} else break;
			rslt.num[i] %= 10;
		}
//同号为正 异号为负
		rslt.symbol = symbol ^ bInt.symbol;
		return rslt;
	}
    BigInt operator / (const BigInt bInt) const
    {
        BigInt tmp;
        string rsltS;
        if(bInt == 0) return BigInt(0); //除数为0 返回0
//获取相除的两个数字的长度
        vector<int>::size_type lenA(num.size()), lenB(bInt.num.size()), len(0);
//按倒序位读取被除数
        vector<int>::size_type i(lenA);
        while(i--)
        {
            if(tmp == 0) tmp.num.pop_back();
            tmp.num.insert(tmp.num.begin(), num[i]); //插入一个数
//开始试除
            BigInt tmp2; //存储试除
            int i(10);
            while(i--) //由大到小进行试除运算
            {
                tmp2 = (bInt < 0 ? -bInt : bInt) * i; //这里对除数为负数的情况作了一些判断，我们在运算过程中要确保符号均为正
                tmp2 = tmp - tmp2; //减去试除结果
                if(tmp2 >= 0) //首个非负的试除结果
                {
                    rsltS += i + '0'; //商
                    tmp = tmp2;
                    break;
                }
            }
        }
        BigInt rslt(rsltS); //结果 该构造函数自动去除前导零
//同号为正 异号为负
        rslt.symbol = symbol ^ bInt.symbol;
        if(rslt.symbol && rslt*bInt != (*this)) {
            rslt-=1;
        }
        return rslt;
    }
    BigInt operator%(const BigInt bInt){
        return *this-((*this/bInt)*bInt);
	}
//重载 += 运算符 使之支持用 += 进行高精度整数的加法运算
	BigInt operator+=(const BigInt bInt) {
		*this = *this + bInt;
		return *this;
	}

//重载 -= 运算符 使之支持用 -= 进行高精度整数的减法运算
	BigInt operator-=(const BigInt bInt) {
		*this = *this - bInt;
		return *this;
	}

//重载 *= 运算符 使之支持用 *= 进行高精度整数的乘法运算
	BigInt operator*=(const BigInt bInt) {
		*this = *this * bInt;
		return *this;
	}

//重载 < 运算符 使之支持使用 < 直接进行高精度整数的比较
	bool operator<(const BigInt bInt) const {
		vector<int>::size_type bLen(bInt.num.size());
        if ((*this) == 0 && bInt == 0) {
            return false;
        }
		if (!bInt.symbol && symbol) return true; //左正 右负
		else if (bInt.symbol && !symbol) return false; //左负 右正
		else if (num.size() != bLen) //长度不一样，直接返回大小结果
		{
			if (!symbol) return num.size() < bLen;
			else return num.size() > bLen;
		}
//由末位开始逐个比较
		for (vector<int>::size_type i(bLen - 1); i > 0; --i) {
			if (num[i] != bInt.num[i]) {
				if (!bInt.symbol && !(*this).symbol) return num[i] < bInt.num[i];
				else return bInt.num[i] < num[i];
			}
		}
		if (!bInt.symbol && !symbol) return num[0] < bInt.num[0]; //左正 右正
		else return bInt.num[0] < num[0]; //左负右负
	}

//重载其它比较运算符
	bool operator>(const BigInt bInt) const {
		return bInt < *this;
	}

	bool operator<=(const BigInt bInt) const {
		return !(*this > bInt);
	}

	bool operator>=(const BigInt bInt) const {
		return !(*this < bInt);
	}

	bool operator!=(const BigInt bInt) const {
		return !(*this==bInt);
	}

	bool operator==(const BigInt bInt) const {
        if (this->num.size() == 1 && this->num[0] == 0 && bInt.num.size() == 1 && bInt.num[0] == 0) {
            return true;
        }
	    if(bInt.symbol!=this->symbol || this->num.size()!=bInt.num.size()) {
            return false;
	    }
        for (int i = 0; i < bInt.num.size(); i++) {
            if (bInt.num[i] != this->num[i]) {
                return false;
            }
        }
        return true;
	}

	explicit operator double() {
		double tmp = 0;
		for (int i = num.size() - 1; i >= 0; i--) {
			tmp *= 10;
			tmp += num[i];
		}
		if (symbol) {
			tmp *= -1;
		}
		return tmp;
	}
};

//重载C++输入流运算符 使之支持C++IO流直接输入高精度整数
std::istream &operator>>(std::istream &in, BigInt &x) {
	string tmp;
	in >> tmp;
	x = tmp;
	return in;
}

//重载C++输出流运算符 使之支持C++IO流直接输出高精度整数
std::ostream &operator<<(std::ostream &out, const BigInt &x) {
	if (x.symbol && x!=0) out << '-';
//以数字的正确顺序输出
	for (vector<int>::size_type i(x.num.size() - 1); i > 0; --i) {
		out << x.num[i];
	}
	out << x.num[0];
	return out;
}